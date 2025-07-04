library(GEOquery)
library(stringr)


if(!file.exists("geo_downloads"))
  dir.create("geo_downloads")

my.gse <- "GSE164191"

my.geo.gse <- getGEO(my.gse, filename = NULL, destdir = "./geo_downloads", GSElimits = NULL, GSEMatrix = TRUE, AnnotGPL = FALSE, getGPL = FALSE)
my.geo.gse
my.geo.gse <- my.geo.gse[[1]]

untar(paste0("geo_downloads/",my.gse,"/",my.gse,"_RAW.tar"), exdir = paste0("geo_downloads/",my.gse,"/CEL"))
filepath <- paste0("geo_downloads/", my.gse, "/CEL/")

files <- list.files(filepath, pattern = "\\.gz$")

for (file in files) {
  new_name <- str_replace(file, "^(GSM\\d+).*$", "\\1.CEL.gz")
  file.rename(file.path(filepath, file), file.path(filepath, new_name))
}
my.cels <- list.files(paste0("geo_downloads/",my.gse,"/CEL"))

my.pdata <- as.data.frame(pData(my.geo.gse), stringsAsFactors = F)
head(my.pdata)
dim(my.pdata)
colnames(my.pdata)

rownames(my.pdata) == my.cels
table(rownames(my.pdata) == my.cels)

head(my.cels)
head(rownames(my.pdata))

temp.rownames <- paste(rownames(my.pdata), ".CEL.gz", sep = "")
table(temp.rownames == my.cels)

rownames(my.pdata) <- temp.rownames
rm(temp.rownames)
table(rownames(my.pdata) == my.cels)

write.table(my.pdata, file = paste0("geo_downloads/",my.gse,"/CEL/",my.gse,"_PhenoData.txt"), sep = "\t", quote = F)


if(!requireNamespace("BiocManager", quietly = TRUE))
  install.packages("BiocManager")

BiocManager::install("affy")

library(affy)
cel.path <- paste0("geo_downloads/",my.gse,"/CEL")
my.affy <- ReadAffy(celfile.path = cel.path, phenoData = paste(cel.path, paste0(my.gse,"_PhenoData.txt"), sep = "/"))
show(my.affy)

head(exprs(my.affy))

colnames(pData(my.affy))
pData(my.affy)
pData(my.affy)$title

my.rma <- rma(my.affy, normalize = T, background = T)
head(exprs(my.rma))

BiocManager::install("hgu133plus2.db")
BiocManager::install("annotate")
BiocManager::install("R2HTML")
my.rma@annotation
library(hgu133plus2.db)
library(annotate)
library(R2HTML)

ID <- featureNames(my.rma)
Symbol <- getSYMBOL(ID,"hgu133plus2.db")
sym <- as.data.frame(Symbol)

data <- as.data.frame(exprs(my.rma))
data <- cbind(sym, data)

i <- which(is.na(data$Symbol) == TRUE)
data<-data[-c(i),]

rownames(data) <- data[,1]

X <- data.table::as.data.table(data)
final_data <- X[,lapply(.SD,mean),"Symbol"]
final_data <- as.data.frame(final_data)
rownames(final_data) <- final_data[,1] 
final_data <- final_data[,-c(1)]

saveRDS(final_data,"geo_downloads/GSE164191/GSE164191_raw.RDS")

final_data = t(final_data)
metadata = pData(my.affy)
table(rownames(final_data) == rownames(metadata))

final_data = as.data.frame(final_data)
final_data$status = metadata$disease.status.ch1

write.csv(final_data,file="geo_downloads/GSE164191/GSE164191.csv")
















from scipy.io import wavfile
from scipy.fft import fft
from scipy.signal import find_peaks
import matplotlib.pyplot as plt
import numpy as np

#soru 1
fs = 8000

myNumber = "05418493876"

DTMF_array = [(941,1336),(697,1209),(697, 1336),(697, 1477),(770, 1209),(770, 1336),(770, 1477),(852, 1209),(852, 1336),(852, 1477),(941, 1209),(941, 1477)]
phoneNumber = []
zeroList = [0]*800
amplitude = 0.1
t = np.linspace(0, 0.1, 800)
for i in range (len(myNumber)):
    tmp = amplitude * np.sin(2*np.pi*DTMF_array[int(myNumber[i])][0]*t) + amplitude * np.sin(2*np.pi*DTMF_array[int(myNumber[i])][1]*t)
    phoneNumber.extend(tmp)
    phoneNumber.extend(zeroList)
phoneNumber = np.array(phoneNumber)

t = np.linspace(0,len(phoneNumber)/8000, len(phoneNumber))
plt.plot(t, phoneNumber)
plt.title("Plot Graph of '05418493876.wav'")
plt.show()
plt.stem(t, phoneNumber)
plt.title("Stem Graph of '05418493876.wav'")
plt.show()

wavfile.write("05418493876.wav", fs, phoneNumber.astype(np.float32))

#soru 2
fs, phoneNumber = wavfile.read("05418493876.wav")

length = np.floor(len(phoneNumber)/len(myNumber))
length = int(length)
button = np.empty
x = np.arange(0, length)
myPhoneNumber = []
figure = plt.figure("Telephone Number Frequency of '05418493876.wav'")
for i in range (len(myNumber)):
    button = phoneNumber[length*i:length*(i+1)]
    FFT = fft(button, fs)
    
    peaks = find_peaks(np.abs(FFT),22)
    index = DTMF_array.index((peaks[0][0]-1, peaks[0][1]-2))
    myPhoneNumber.append(index)
    addSubPlot = figure.add_subplot(11, 1, i+1)
    addSubPlot.plot(x, np.abs(FFT[0:length]))
    addSubPlot.set_title(myPhoneNumber[i])
plt.show()


print(f"Password = {myPhoneNumber}")

#soru 3
fs, phoneNumber = wavfile.read("Ornek.wav")


t = np.linspace(0,len(phoneNumber)/fs, len(phoneNumber))
plt.plot(t, phoneNumber)
plt.title("Plot Graph of 'Ornek.wav'")
plt.show()
plt.stem(t, phoneNumber)
plt.title("Stem Graph of 'Ornek.wav'")
plt.show()

length = np.floor(len(phoneNumber)/11)
length = int(length)
button = np.empty
myPhoneNumber = []
x = np.arange(500, length)
figure = plt.figure("Telephone Number Frequency of 'Ornek.wav'")
for i in range (11):
    button = phoneNumber[length*i:length*(i+1)]
    
    FFT = fft(button, fs)
    peaks = find_peaks(np.abs(FFT[500:length]),17000)
    
    index = DTMF_array.index((peaks[0][0]+500, peaks[0][1]+500))
    myPhoneNumber.append(index)
    addSubPlot = figure.add_subplot(11, 1, i+1)
    addSubPlot.plot(x, np.abs(FFT[500:length]))
    addSubPlot.set_title(myPhoneNumber[i])
plt.show()
print(f"Password = {myPhoneNumber}")
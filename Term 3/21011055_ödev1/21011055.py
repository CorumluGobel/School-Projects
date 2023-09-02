import matplotlib.pyplot as plt
import numpy as np
import sounddevice as sd
from colorama import Style
#soru 1
def myConv(x,y,N,M):
    a = [0]*(N+M-1)
    for i in range(0,N+M-1):
        for j in range (0,M):
            if (i-j) < N and i >= j:
                a[i] = a[i] + y[j]*x[i-j]
    return a
#input
N = int(input("N: "))
M = int(input("M: "))

x = [0]*N
y = [0]*M
for i in range (0,N):
    x[i] = int(input(f"x[{i}]: "))
x0 = int(input("x'in 0 noktası: "))
for i in range (0,M):
    y[i] = int(input(f"y[{i}]: "))
y0 = int(input("y'nin 0 noktası: "))
a0 = x0 + y0

#soru 2
#mine
a = myConv(x,y,len(x),len(y))
t = np.arange(0-a0,len(a)-a0)
print("MyConv")
print("x*y =", end = ' ')
for i in range(0,len(a)):
    if i == a0:
        print(Style.BRIGHT,a[i],Style.RESET_ALL, end = '')
    else:
        print(a[i], end = ' ')
plt.stem(t,a)
plt.xlabel("x")
plt.ylabel("y")
plt.title("My Conv")
plt.show()
#built-in
a = np.convolve(x,y)
print("\nBuilt-in")
print("x*y =", end = ' ')
for i in range(0,len(a)):
    if i == a0:
        print(Style.BRIGHT,a[i],Style.RESET_ALL, end = '')
    else:
        print(a[i], end = ' ')
plt.stem(t,a)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Built-in Conv")
plt.show()

#soru 3
#5secVoiceRecording
duration = 5
fs = 44000
print("\nStart Speaking")
x1 = sd.rec(int(duration*fs), samplerate = fs, channels = 1)
sd.wait()
print("Recording Ended")

#10secVoiceRecording
duration = 10
fs = 44000
print("Start Speaking")
x2 = sd.rec(int(duration*fs), samplerate = fs, channels = 1)
sd.wait()
print("Recording Ended")

#soru 4
M = 4
S = (M*400)+1
h = [0] * S
h[0] = 1
for k in range (1,M+1):
    h[400*k] = 0.8*k
myY1 = myConv(x1[:,0],h,len(x1[:,0]),len(h))
myY2 = myConv(x2[:,0],h,len(x2[:,0]),len(h))
Y1 = np.convolve(x1[:,0],h)
Y2 = np.convolve(x2[:,0],h)

#5sec
print("Playing Input")
sd.play(x1)
sd.wait()
print("Playing My Output")
sd.play(myY1)
sd.wait()
print("Playing Output")
sd.play(Y1)
sd.wait()
print("Playback Ended")

#10sec
print("Playing Input")
sd.play(x2)
sd.wait()
print("Playing My Output")
sd.play(myY2)
sd.wait()
print("Playing Output")
sd.play(Y2)
sd.wait()
print("Playback Ended")


# GPS_Timer
realize a function based on stm8s MCU, Atomthread, Oled and GPS patch

#Ideas/Motication/Requirement
to realize a portable timer, that no need extra electrical power directly, or can be powered by solar.

thus we need:
1)a display ---->use 128*64 oled
   display chinese time,data,speed and located flag(maybe lantitude, longitude later)

2)power ---->solar panel or others
3)MCU----stm8s
because it a simple function, and i am ralatively familiar with stm family.
4)OS----atomthread
it is designed for mini os mcu such as stm8s.even though we do not need to use OS, it is good for expand and read.
5)GPS patch-L80


#refer:
1) atomthread is open source OS. http://atomthreads.com/
import csv
import serial

SerialIn = serial.Serial("COM3",115200)

with open('record.csv', mode='a' , newline='') as am2320_file:
   am2320_writer = csv.writer(am2320_file, delimiter=',')
   line_count=0 
   
   while True:
         
         while SerialIn.in_waiting:
               data_in = SerialIn.readline() 
               data_raw = data_in.decode('utf-8') 
              
               
               if line_count!=0:
                  temper = data_raw[:-2]
                  print(temper)
                  temper = temper.split(',')
                  for i in range(len(temper)):
                       
                        temper[i] = int(temper[i])
                        
                  cat = 3 #紀錄類別
                  temper.append(cat)
                  print("recording:",cat, len(temper))
                  am2320_writer.writerow(temper)
               

               line_count = line_count + 1

   # except KeyboardInterrupt:
   #     SerialIn.close()   

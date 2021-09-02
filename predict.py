import numpy as np
import joblib
import serial
import re
def read_label_file(file_path):
  """
  This function supports following formats:
  1. Each line contains id and description separated by colon or space.
     Example: '0:cat' or '0 cat'.
  """
  with open(file_path, 'r', encoding='utf-8') as f:
    lines = f.readlines()
  ret = {}
  for row_number, content in enumerate(lines):
    pair = re.split(r'[:\s]+', content.strip(), maxsplit=1)
    if len(pair) == 2 and pair[0].strip().isdigit():
      ret[int(pair[0])] = pair[1].strip()
    else:
      ret[row_number] = pair[0].strip()
  return ret
model_name = 'LR_model'
label_name = 'labelmap'

loaded_model = joblib.load(model_name) ## Load model 
SerialIn = serial.Serial("COM3",115200) ## Connect to COM
line_count= 0 

label = read_label_file(label_name)
print('COM ready')
while True:
    
    while SerialIn.in_waiting:
        data_in = SerialIn.readline() 
        data_raw = data_in.decode('utf-8') 
        if line_count!=0:
            temper = data_raw[:-2]
        
            temper = temper.split(',')
            for i in range(len(temper)):

                temper[i] = int(temper[i])
       
           
            result = loaded_model.predict([temper[1:]])
            print(label[result[0]])

        line_count = line_count + 1

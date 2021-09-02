import pandas as pd
from sklearn.linear_model import LogisticRegression
from matplotlib import pyplot as plt   
import numpy as np
import joblib
from sklearn.model_selection import train_test_split

from sklearn.metrics import confusion_matrix #Confusion matrix
from sklearn.metrics import accuracy_score # Accuracy score
from scipy import optimize as op
dataset = pd.read_csv("record.csv")
# print (dataset['1'].value_counts())
Species = [0,1,2,3,4,5,6,7,8,9,10] #開關機，溫度up 溫度down
# Number of examples
m = dataset.shape[0]
# Features
n = 99
# Number of classes
k = 11
print(dataset)
X = np.ones((m,n))
y = np.array((m,1))

for i in range(1,100):
    
    X[:,i-1] = dataset[str(i)].values
    
print(X[0],len(X[0]))
# Labels
y = dataset['label'].values
# for j in range(n):
#     X[:, j] = (X[:, j] - X[:,j].mean())


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 11)
np.set_printoptions(suppress=True)
# it shows 80% of data is split for training and 20% of the data goes to testing.







model = LogisticRegression(random_state=3, solver='lbfgs',
                        multi_class='multinomial').fit(X_train, y_train) #

y_result = model.predict(X_test)
y_proba = model.predict_proba(X_test) 

print('acc : %.2f'%(accuracy_score(y_test, y_result)*100),"%")

#x=[66,34,8,9,8,25,8,9,8,8,8,26,8,25,8,25,8,25,9,25,8,9,8,25,9,24,8,9,8,9,8,8,8,9,8,9,8,25,8,9,8,25,8,9,8,8,8,26,8,8,8,9,8,25,8,26,8,8,8,26,8,25,8,9,8,25,8,25,8,9,8,25,8,9,8,25,8,26,8,8,8,9,8,9,8,8,8,9,8,25,8,9,8,9,8,25,8,25,8]

joblib.dump(model, 'LR_model')
print('Model saved!')
from sklearn.metrics import classification_report
print(classification_report(y_test, y_result))


# for flower in Species:
#     #set the labels in 0 and 1
#     tmp_y = np.array(y_train == flower, dtype = int)
#     model = logisticRegression(fit_intercept=False)
#     model.fit(X_train, tmp_y)
#     # optTheta = logisticRegression(X_train, tmp_y, np.zeros((n + 1,1)))
#     # all_theta[i] = optTheta.T
#     i += 1

#     Prob = sigmoid(X_test.dot(all_theta.T)) # probability for each id
#     pred = [Species[np.argmax(Prob[i, :])] for i in range(X_test.shape[0])]

#     print("Test Accuracy %.2f " %(accuracy_score(y_test, pred)*100.0) ,'%')
#     print("Next iter")

# # Prob = sigmoid(X_test.dot(all_theta.T)) # probability for each id
# # pred = [Species[np.argmax(Prob[i, :])] for i in range(X_test.shape[0])]

# # print(" Test Accuracy ", accuracy_score(y_test, pred) * 100 , '%')
# joblib.dump(optTheta, 'LR_model')
# print('model saved!')
# from sklearn.metrics import classification_report
# print(classification_report(y_test, pred))
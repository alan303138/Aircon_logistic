import pandas as pd
from sklearn.linear_model import LogisticRegression
from matplotlib import pyplot as plt   
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix #Confusion matrix
from sklearn.metrics import accuracy_score # Accuracy score
from scipy import optimize as op
dataset = pd.read_csv("record.csv")
# print (dataset['1'].value_counts())
Species = [1, 2, 3] #開關機，溫度up 溫度down
# Number of examples
m = dataset.shape[0]
# Features
n = 100
# Number of classes
k = 3

X = np.ones((m,n + 1))
y = np.array((m,1))
for i in range(1,n):
    X[:,i] = dataset[str(i)].values

# Labels
y = dataset['label'].values
for j in range(n):
    X[:, j] = (X[:, j] - X[:,j].mean())
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 11)
# it shows 80% of data is split for training and 20% of the data goes to testing.
X = dataset.drop(['label'], axis=1)
y = dataset['label']
# print(X.head())
# print(y.head())
print(X_train.shape)

print(y_test.shape)


#=======#
def sigmoid(z):
    return 1.0 / (1 + np.exp(-z))
#____________________________________________________________________________#
# Regularized cost function
def reglrCostFunction(theta, X, y, lambda_s = 0.1):
    m = len(y)
    h = sigmoid(X.dot(theta))
    J = (1 / m) * (-y.T.dot(np.log(h)) - (1 - y).T.dot(np.log(1 - h)))
    reg = (lambda_s/(2 * m)) * np.sum(theta**2)
    J = J + reg
 
    return J
#____________________________________________________________________________#
# Regularized gradient function
def reglrGradient(theta, X, y, lambda_s = 0.1):
    m, n = X.shape
    theta = theta.reshape((n, 1))
    y = y.reshape((m, 1))
    h = sigmoid(X.dot(theta))
    reg = lambda_s * theta /m
    gd = ((1 / m) * X.T.dot(h - y)) 
    gd = gd + reg

    return gd
#____________________________________________________________________________#
# Optimizing logistic regression (theta)
def logisticRegression(X, y, theta):
    result = op.minimize(fun = reglrCostFunction, x0 = theta, args = (X, y),
                         method = 'TNC', jac = reglrGradient)
    
    return result.x
#=======#

# Training
all_theta = np.zeros((k, n + 1))

# One vs all
i = 0
for idd in Species:
    tmp_y = np.array(y_train == idd, dtype = int)
    optTheta = logisticRegression(X_train, tmp_y, np.zeros((n + 1,1)))
    all_theta[i] = optTheta
    i += 1
Prob = sigmoid(X_test.dot(all_theta.T)) # probability for each id
pred = [Species[np.argmax(Prob[i, :])] for i in range(X_test.shape[0])]

print(" Test Accuracy ", accuracy_score(y_test, pred) * 100 , '%')
cnfm = confusion_matrix(y_test, pred, labels = Species)
import seaborn as sb
sb.heatmap(cnfm, annot = True, xticklabels = Species, yticklabels = Species)
from sklearn.metrics import classification_report
print(classification_report(y_test, pred))
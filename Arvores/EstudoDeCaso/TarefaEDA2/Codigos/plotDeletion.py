import matplotlib.pyplot as plt
import numpy as np 
  
x = [25,50,75,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,7000,7500,8000,8500,9000,9500,10000] 



yAVL = [59,69,71,74,79,90,92,91,97,95,101,104,101,102,110,111,110,116,107,113,118,112,110,125,123,129,132,137,132,126,134,129,145,137,147,140,148,136,143,146]
yRB = [22,24,25,26,29,29,30,31,32,31,32,33,33,34,34,34,35,33,34,34,35,34,38,37,37,38,40,39,39,39,40,41,42,42,42,44,42,42,42,44]
yB1 =  [28,33,35,38,42,40,44,45,47,46,46,48,49,49,50,49,52,50,51,52,52,52,55,57,58,59,61,61,62,63,64,62,63,66,63,64,65,64,65,66]
yB5 = [27,28,30,34,36,37,37,37,38,39,39,36,40,40,41,41,42,43,42,44,43,42,44,44,45,45,47,45,46,49,45,48,49,51,47,51,52,50,52,52]
yB10 = [29,33,34,37,38,36,42,39,40,45,44,41,40,43,45,44,43,42,41,44,45,41,50,47,46,49,50,48,50,51,47,51,51,50,52,52,54,54,53,53]


plt.ylim([0,200])
plt.xlim([25,10000])

plt.plot(x, yAVL)
plt.plot(x,yRB)
plt.plot(x,yB1)
plt.plot(x,yB5)
plt.plot(x,yB10)


plt.legend(["AVL","Rubro-Negra", "B-1","B-5","B-10"],loc = "upper left")
plt.xlabel("Tamanho do Conjunto de Dados") 
plt.ylabel("Esforço") 
plt.title('Árvores - Deleção de 1 Nó') 
plt.show() 
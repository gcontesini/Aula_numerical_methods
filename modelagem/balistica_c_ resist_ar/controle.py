import os															##biblioteca que contem a função de saida de comandos (script)##
ang=10															#angulo inicial##
dang=10															##variação do angulo##
dk=0.1															##variação do k(constante de resistividade do ar)##
for j in range(8):													##laço de variação do angulo##
	k=0.1														##Reatribuição do K##
	for i in range():												##laço de variação do k##
		print ang,k												##tecnica utilizada para saber como o script esta funcionando##
		os.system("./tr.out > ang"+str(ang)+"xK"+str(k)+".dat "+str(ang)+str(k))	##função que retorna um comando para o terminal##
		k+=dk													##variação do k##
	ang+=dang			
											##variação do angulo (ang)##
	##para executar recomenda-se que retire os comentarios do codigo##

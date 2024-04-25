import random

N = 10  # tamanho da janela
random.seed(27250420241021)  # Definindo a semente para garantir a repetibilidade

# função que cria um vetor com 1000 posições com valores aleatórios entre 0 e 4999
vetor = [random.randint(0, 4999) for _ in range(50)]

# Função para definir o valor mais proximo do head com base na direção
def closest(lista, head, direcao):
    if direcao == 0:
        prox = 99999
        for i in lista:
            if i < prox:
                prox = i
        return prox
    
    if direcao == 1:
        prox = 99999
        for i in lista:
            if i > head:
                if i < prox:
                    prox = i
        return prox
    
    if direcao == -1 :
        prox = -99999
        for i in lista:
            if i < head:
                if i > prox:
                    prox = i
        return prox



# Função para simular o algoritmo SCAN    
def scan(request, janela, head = 0):
    prox = closest(janela, head, 0)
    braco = 0
    direcao = 1 # 1 = direita, -1 = esquerda (1 por padrão pois no enunciado é especificado que o braço inicia no 0) 
    
    while(request != []):
        if(braco == prox): 
            print("-----------------------------------------------------------------------------------")
            print("Head: ", braco) 
            print(janela)
            print(request)
            janela.remove(prox)            
            prox = closest(janela, braco, direcao)
            
            if(request != []):
                janela.append(request[0])
                request.remove(request[0])
        
        if(braco == 4999):
            direcao = -1
        if(braco == 0):
            direcao = 1

        braco = braco + (1*direcao)
       
janela = vetor[:N]
del vetor[:N]     
scan(vetor, janela)   


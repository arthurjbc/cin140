
def entrada():
    lista = input().split(" ")
    return lista

def bubbleSort(lista):
    for i in range(len(lista)):
        for j in range(len(lista)-i-1):
            if lista[j+1]<lista[j]:
                temp = lista[j+1]
                lista[j+1]=lista[j]
                lista[j]=temp
    return lista

lista = entrada()
print(bubbleSort(lista))
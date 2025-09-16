lista = [89, 45, 68, 90, 29, 34, 17]

def selectionSort(lista):
    print (len(lista))
    for i in range(len(lista)):
        min = i
        for j in range(i+1, len(lista)):
            if lista[j] < lista[min]:
                min = j
        temp = lista[min]
        lista[min] = lista[i]
        lista [i] = temp

    return lista

print(selectionSort(lista))
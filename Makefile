selection:
	g++ selectionSort.cpp -o selection.out

bubble:
	g++ bubbleSort.cpp -o bubble.out

insertion:
	g++ insertionSort.cpp -o insertion.out

quick:
	g++ quickSort.cpp -o quick.out

binary:
	g++ binarySearch.cpp -o binary.out

merge:
	g++ mergeSort.cpp -o merge.out

clean:
	rm -f *.out
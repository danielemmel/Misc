all: compile run_tests run_main clean

compile:
	@g++ -o all_tests src/utils.cpp tests/templateHeapTests.cpp tests/intHeapTests.cpp src/heap/maxHeapInt.cpp tests/bubbleSortTests.cpp src/sorting/bubbleSort.cpp tests/quickSortTests.cpp src/sorting/quickSort.cpp tests/mergeSortTests.cpp src/sorting/mergeSort.cpp -lgtest -lpthread -lgtest_main
	@g++ -o main main.cpp src/utils.cpp src/sorting/bubbleSort.cpp src/sorting/quickSort.cpp src/sorting/mergeSort.cpp src/heap/maxHeapInt.cpp
run_tests:
	@echo "Running tests:"
	@./all_tests
run_main:
	@echo
	@echo "Running main:"
	@./main
clean:
	@rm -f all_tests
	@rm -f main

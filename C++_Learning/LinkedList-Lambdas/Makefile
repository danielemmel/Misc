all: compile run_tests run_main clean

compile:
	@g++ -o int_tests src/tests/MyLinkedListIntTests.cpp src/MyLinkedListInt.cpp -lgtest -lpthread
	@g++ -o template_tests src/tests/MyLinkedListTemplateTests.cpp src/MyLinkedList.h -lgtest -lpthread
	@g++ -o main src/main.cpp src/MyLinkedListInt.cpp
run_tests:
	@echo "Running tests:"
	@./int_tests
	@echo
	@./template_tests
run_main:
	@echo
	@echo "Running main:"
	@./main
clean:
	@rm -f int_tests
	@rm -f template_tests
	@rm -f main

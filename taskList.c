/*
TASK:
	Найти все элементы, больше среднего арефметического элментов списка
	и переставить их в начало списка
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

struct List{
	int m_data;// значение элемента
	struct List* m_next; // указатель на следующий элемент
};

int main() {

	SetConsoleCP(1251);			//русский язык
	SetConsoleOutputCP(1251);	//русский язык
	
	int lenght;
	struct List* m_first;

	m_first = NULL;
	
	printf("Сколько элементов Вы хотите, чтобы содержал лист?\n");
	scanf("%d", &lenght);

	if (lenght <= 0) {
		printf("Ошибка: длина списка должна быть больше 0");
		exit(0);
	}
	

	//выделяем память
	m_first = (struct List*)malloc(sizeof(struct List));
	struct List* m_temp = m_first;
	for (size_t count = 1; count < lenght; ++count) {
		m_temp->m_next = (struct List*)malloc(sizeof(struct List));
		m_temp = m_temp->m_next;
	}

	//вводим элементы в список
	m_temp = m_first;
	for (int count = 0; count < lenght; ++count) {
		printf("Введите элемент индекса %d:\n", count);
		scanf("%d", &m_temp->m_data);
		m_temp = m_temp->m_next;
	}

	//вывыодим элементы списка
	m_temp = m_first;
	printf_s("Вы вели следующий список: \n");
	for (int count = 0; count < lenght; ++count) {
		printf("%d ", m_temp->m_data);
		m_temp = m_temp->m_next;
	}

	//поиск среднего арефметического
	double sum = 0, middleArefmeticSum = 0;
	m_temp = m_first;
	for (int count = 0; count < lenght; ++count) {
		sum += m_temp->m_data;
		m_temp = m_temp->m_next;
	}
	middleArefmeticSum = sum / lenght;
	printf("\nСреднее арефметическое списка: %lf", middleArefmeticSum);

	//перемещение элементов
	m_temp = m_first;
	int k = 0;

	struct List* m_new_list1 = (struct List*)malloc(sizeof(struct List));
	struct List* m_new_list_temp1 = m_new_list1;
	for (size_t count = 1; count < lenght; ++count) {
		m_new_list_temp1->m_next = (struct List*)malloc(sizeof(struct List));
		m_new_list_temp1 = m_new_list_temp1->m_next;
	}
	m_new_list_temp1 = m_new_list1;
	struct List* m_new_list2 = (struct List*)malloc(sizeof(struct List));
	struct List* m_new_list_temp2 = m_new_list2;
	for (size_t count = 1; count < lenght; ++count) {
		m_new_list_temp2->m_next = (struct List*)malloc(sizeof(struct List));
		m_new_list_temp2 = m_new_list_temp2->m_next;
	}
	m_new_list_temp2 = m_new_list2;
	for (int count = 0; count < lenght; ++count) {
		if (m_temp->m_data >= middleArefmeticSum) {
			++k;
			m_new_list_temp1->m_data = m_temp->m_data;
			m_new_list_temp1 = m_new_list_temp1->m_next;
			m_temp = m_temp->m_next;
		}
		else {
			m_new_list_temp2->m_data = m_temp->m_data;
			m_new_list_temp2 = m_new_list_temp2->m_next;
			m_temp = m_temp->m_next;
		}
	}

	m_first = m_new_list1;
	for (int count = 1; count < k; ++count) {
		m_new_list1 = m_new_list1->m_next;
	}
	m_new_list1->m_next = m_new_list2;

	m_temp = m_first;
	printf_s("\nВы вели следующий список: \n");
	for (int count = 0; count < lenght; ++count) {
		printf("%d ", m_temp->m_data);
		m_temp = m_temp->m_next;
	}

	m_temp = m_new_list1;
	for (int count = 0; count < lenght; m_temp = m_new_list1) {
		m_new_list1 = m_new_list1->m_next;
		free(m_temp);
	}
	m_temp = m_new_list2;
	for (int count = 0; count < lenght; m_temp = m_new_list2) {
		m_new_list2 = m_new_list2->m_next;
		free(m_temp);
	}


	//освобождаем память
	m_temp = m_first;
	for (int count = 0; count < lenght; m_temp = m_first){
		m_first = m_first->m_next;
		free(m_temp);
	}

	return 0;
}

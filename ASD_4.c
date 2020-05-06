#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct books{
	char year[5];
	char title[21];
	struct books *next;
}book;

book *create_list(char year[], char title[]);
int   my_cmp(char *year1, char *title1, char *year2, char *title2);
book *add_element(book *head, char year[], char title[]);
void  delete_hvost(book **hvost);
void  print_predposled(book *pred);
void  print_list(book *head);
void  delete_all_list(book **hvost);

int main(){
	int  choice_1;
	char year[5], title[21];
	book *head = NULL;                                                     // указатель head на ноль
	while(1){
    	printf("1 -> Add a book v poryadke spadaniya.\n");                 
		printf("2 -> Delete the book s hvosta spiska.\n");
		printf("3 -> Print the prepdposlednuu book.\n");                     
		printf("4 -> Print the spisok.\n");
		printf("5 -> Delete the spisok.\n");
		printf("6 -> END.\n");
    	printf("Your choice is  ");	
    	scanf("%d", &choice_1);
    	switch(choice_1){
    		case 1:
        		printf("Enter a year: \n");
        		scanf("%s",&year);
        		printf("Enter a title : \n");
        		scanf("%s",&title);
				head = add_element(head, year, title);
        	break;                                                        
    		case 2:
        		delete_hvost(&head);
	    	break;
    		case 3:
				print_predposled(head);
			break;
    		case 4:
    			if(head == NULL){
        			printf("The list is empty.\n");    					
				}
				else{
					print_list(head);
				}
			break;
			case 5:
        		delete_all_list(&head);
			break;
        	case 6:
        		delete_all_list(&head);
				return 0;
			default:
				delete_all_list(&head);
				printf("ERROR\n");
				return 0;	
		}
	}
}

book *create_list(char year[], char title[]){                 // Создаем первый эдемент списка 
	book *ress = (book *)malloc(sizeof(book));
	strcpy(ress->year, year);                                       
	strcpy(ress->title, title);
	ress->next = NULL;
	return ress;  
}

book *add_element(book *head, char year[], char title[]){
    if (head == NULL){
        head = create_list(year, title);                                 // если указатель на голову равен 0, создаем первый элемент спика 
        return head;
    }
    book *prev = NULL;                                                 // доп указатель на прошлый элемент
    book *curr = head;                                                             
    while((curr != NULL) && (!my_cmp(title, year, curr->title, curr->year))){
        prev = curr;                                                                  // поиск места вставки 
        curr = curr->next;                                                           
    }
    book *new_elem = create_list(year, title);
    if (!prev){                                                        // если нужно вставить на первое место
        new_elem->next = head;
        head = new_elem;
    }
	else{
        prev->next = new_elem;                                                           // вставка между элементами 
        new_elem->next = curr;
    }
    return head;
}

int my_cmp(char *title1, char *year1, char *title2, char *year2){                              // сравнение двух элементов 
	int i;
	int max_len_year  = strlen(year1) >= strlen(year2) ? strlen(year1) : strlen(year2);
    int max_len_title  = strlen(title1) >= strlen(title2) ? strlen(title1) : strlen(title2);     // находим длину названия книги
    if (strlen(year1) != strlen(year2)){              
        return (strlen(year1) > strlen(year2));                         // возвращаем 0 или 1 в зависимости от кого, какой год больше 
    }
    for (i = 0; i < max_len_year; ++i){
        if (year1[i] != year2[i]) {
            return (*(year1+i) > *(year2+i));                            // возвращаем 0 или 1 в зависимости от кого, какой год больше 
        }
    }
    if (strlen(title1) != strlen(title2)){              
        return (strlen(title1) < strlen(title2));                         // возвращаем 0 или 1 в зависимости от кого, какое название длинее
    }
    for (i = 0; i < max_len_title; ++i){                                                           
        if (title1[i] != title2[i]){
            return (*(title1+i) < *(title2+i));                       // возвращаем 0 или 1 в зависимости от кого, какой символ на  *(title+i) больше
        }
    }
    return 0;
}

void delete_hvost(book **hvost){                                     // удаляем последний элемент списка
	if(*hvost == NULL){ 
		printf("Doesn`t exist.\n");                               
		return;                                                      // проверка на существования хоча б одного элемента 
	}
	if((*hvost)->next == NULL){                                    
    	free(*hvost);
    	*hvost = NULL;                                        // если он один-он хвост 
    	return;
	}
	book *t = *hvost;
	while (t->next->next != NULL){                                  // поиск хвоста
		t = t->next;
	}
	free(t->next);
	t->next = NULL;
}

void print_predposled(book *pred){            // выводим предпоследний элмент списка 
	if(pred==NULL){
		printf("Doesn`t exist.\n");
		return;
	}
	if(pred->next == NULL){
		printf("Doesn`t exist.\n");
		return;
	}                                                                                
	while (pred->next->next!=NULL){             // ищем предпоследний элемент  
		pred = pred->next;
	}
	printf("%s:%s\n", pred->year, pred->title);
}

void print_list(book *head){                                   // Вывод полного списка
    book *current = head;                                                            // ставим указатель на голову, и ведем его до конца списка 
    while (current != NULL){
    	printf("%s:%s\n",  current->year, current->title);        
        current = current->next;
    }
}

void delete_all_list(book **hvost){                                           // Удаление целого списка
	while(*hvost != NULL){                                             // Пока список  не будет пуст             
    	book *temp = *hvost;                                                   // запис элемент в темп, переходим на след элемент, а темп очищаем                                 
    	*hvost = (*hvost)->next;
    	free(temp);
	}
}

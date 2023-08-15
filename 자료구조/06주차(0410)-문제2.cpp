#include <stdio.h>
#include <stdlib.h>
typedef struct Poly {
	int coef;
	int exp;
	Poly* next;
}Poly;
void appendTerm(Poly* head, int c, int e);
Poly* addPoly(Poly* p1, Poly* p2);
void print(Poly* p);
int main() {
	Poly* p1head = (Poly*)malloc(sizeof(Poly));
	p1head->next = NULL;
	int t1;
	scanf("%d",&t1);
	for (int i = 0; i < t1; i++) {
		int coef, exp;
		scanf("%d %d",&coef, &exp);
		appendTerm(p1head, coef, exp);
	}

	Poly* p2head = (Poly*)malloc(sizeof(Poly));
	p2head->next = NULL;
	int t2;
	scanf("%d", &t2);
	for (int i = 0; i < t2; i++) {
		int coef, exp;
		scanf("%d %d", &coef, &exp);
		appendTerm(p2head, coef, exp);
	}

	Poly *result = addPoly(p1head, p2head);
	print(result);
}

void appendTerm(Poly* head, int c, int e)
{
	if (c == 0) {
		return;
	}
	Poly* p = head;
	Poly* term = (Poly*)malloc(sizeof(Poly));
	term->coef = c;
	term->exp = e;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = term;
	term->next = NULL;
}

Poly* addPoly(Poly* p1, Poly* p2)
{
	Poly *result = (Poly*)malloc(sizeof(Poly));
	result->next = NULL;
	Poly* iter1 = p1->next;
	Poly* iter2 = p2->next;

	while (1) {

		if (iter1 == NULL && iter2 == NULL) {
			break;
		}
		else {
			Poly* term = (Poly*)malloc(sizeof(Poly));
			if (iter1 == NULL) {
				while (iter2 != NULL) {
					appendTerm(result, iter2->coef, iter2->exp);
					iter2 = iter2->next;
				}
			}
			else if (iter2 == NULL) {
				while (iter1 != NULL) {
					appendTerm(result, iter1->coef, iter1->exp);
					iter1 = iter1->next;
				}
			}
			else if (iter1->exp > iter2->exp) {
				appendTerm(result, iter1->coef, iter1->exp);
				iter1 = iter1->next;
			}
			else if (iter1->exp < iter2->exp) {
				appendTerm(result, iter2->coef, iter2->exp);
				iter2 = iter2->next;
			}
			else {
				appendTerm(result, iter1->coef + iter2->coef, iter1->exp);
				iter1 = iter1->next;
				iter2 = iter2->next;
			}
		}

	}

	return result;
}

void print(Poly* p)
{
	Poly* iter = p;
	while (p->next != NULL) {
		p = p->next;
		printf(" %d %d",p->coef, p->exp);
	}
}

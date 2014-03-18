#include <stdio.h>

struct polyItem {
    double coef;
    int exp;
    struct polyItem *next;
};

struct polyItem* PolyAdd(struct polyItem *A, struct polyItem *B);

struct polyItem* PolyAdd(struct polyItem *A, struct polyItem *B)
{
    struct polyItem *p = A, *q = B, *qNext, *pPrior = 0;

    while(p != 0) {
        if(p->exp < q->exp) {
            /* p���Ϊ���е�һ��,�ƶ�p */
            pPrior = p;
            p = p->next;
        } else if(p->exp > q->exp) {
            /* q���Ϊ���е�һ��,������p���֮ǰ,�ƶ�q */
            qNext = q->next;
            if(pPrior != 0) {
                pPrior->next = q;
                q->next = p;
            } else {
                q->next = p;
                A = q;
            }
        } else {
            p->coef += q->coef;

            qNext = q->next;
            free(q);
            q = q->next;

            if(p->coef == 0) {
                qNext = p->next;
                free(p);
                if(pPrior != 0)
                    pPrior->next = qNext;
                else
                    A = qNext;
            } else {
                pPrior = p;
                p = p->next;
            }
        }
    }

    return A;
}

*************
第二章 线性表
*************

课件
====

:download:`下载 <chap2.ppt>`

作业
====

见 `ACM竞赛平台 <http://acm.zjgsu.edu.cn/JudgeOnline/contest.php?cid=1565>`_ .

作业参考答案
============

`问题 A: 逆置线性表(线性表) <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1565&pid=0>`_
----------------------------------------------------------------------------------------------

:download:`数组实现 <A_array.c>`

.. code-block:: c

    void inverse(struct data_container* s)
    {
        int i = 0;
        int j = s->n - 1;
        int tmp;

        while (i < j) {
            tmp = s->pData[i];
            s->pData[i] = s->pData[j];
            s->pData[j] = tmp;
            i++;
            j--;
        }
    }

:download:`链表实现 <A_list.c>`

.. code-block:: c

    void inverse(struct data_listcontainer *s)
    {
        struct data_node* pOld = s->head->next;
        struct data_node* pNew = NULL;
        struct data_node* pTemp;

        while (pOld) {
            pTemp = pOld->next;
            pOld->next = pNew;
            pNew = pOld;
            pOld = pTemp;
        }

        s->head->next = pNew;
    }


`问题 B: 合并链表(线性表) <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1565&pid=1>`_
---------------------------------------------------------------------------------------------

:download:`数组实现 <B_array.c>`

.. code-block:: c

    void merge(struct data_container* s, struct data_container* t, struct data_container* res)
    {
        int i = s->n - 1;
        int j = t->n - 1;

        while (i >= 0 || j >= 0) {
            if (i < 0) {
                insert(res, res->n + 1, t->pData[j]);
                j--;
            } else if (j < 0) {
                insert(res, res->n + 1, s->pData[i]);
                i--;
            }
            else if (s->pData[i] > t->pData[j]) {
                insert(res, res->n + 1, s->pData[i]);
                i--;
            } else {
                insert(res, res->n + 1, t->pData[j]);
                j--;
            }
        }
    }

:download:`链表实现 <B_list.c>`

.. code-block:: c

    void merge(struct data_listcontainer *s, struct data_listcontainer *t)
    {
        struct data_node *p = s->head->next;
        struct data_node *q = t->head->next;

        s->head->next = NULL;
        t->head->next = NULL;

        while (p || q) {
            if (!p)
                q = push_front(s, q);
            else if (!q)
                p = push_front(s, p);
            else if (p->data < q->data)
                p = push_front(s, p);
            else
                q = push_front(s, q);
        }
    }


`问题 C: 删除相同元素(线性表) <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1565&pid=2>`_
-------------------------------------------------------------------------------------------------

:download:`数组实现 <C_array.c>`

.. code-block:: c

    void unique(struct data_container* s)
    {
        int i = 1;

        while (i < s->n) {
            if (s->pData[i] == s->pData[i-1])
                del(s, i+1);
            else
                i++;
        }
    }

:download:`链表实现 <C_list.c>`

.. code-block:: c

    void unique(struct data_listcontainer *s)
    {
        struct data_node* p = s->head->next;
        struct data_node* q;

        while (p->next) {
            if (p->data == p->next->data) {
                q = p->next;
                p->next = q->next;
                free(q);
            } else {
                p = p->next;
            }
        }
    }


`问题 D: 交换节点(线性表) <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1565&pid=3>`_
---------------------------------------------------------------------------------------------
    
:download:`链表实现 <D_list.c>`

.. code-block:: c

    q = s.head;
    p = q->next;
    for (i = 1; i < k; i++) {
        q = p;
        p = p->next;
    }

    q->next = p->next;
    p->next = p->next->next;
    q->next->next = p;


`问题 E: 子序列问题(线性表) <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1565&pid=4>`_
-----------------------------------------------------------------------------------------------

:download:`数组实现 <E_array.c>`

.. code-block:: c

    int subseq(struct data_container *s, struct data_container *t)
    {
        int i, j;
        int M = s->n;
        int N = t->n;

        for (i = 0; i <= M - N; i++) {
            for (j = 0; j < N; j++)
                if (s->pData[i+j] != t->pData[j])
                    break;

            if (j == N)
                return 1;
        }

        return 0;
    }

:download:`链表实现 <E_list.c>`

.. code-block:: c

    int match(struct data_node* p, struct data_node* q)
    {
        while (q) {
            if (!p || p->data != q->data)
                return 0;

            p = p->next;
            q = q->next;
        }

        return 1;
    }

    int subseq(struct data_listcontainer *s, struct data_listcontainer *t)
    {
        struct data_node* p = s->head->next;

        while (p) {
            if (match(p, t->head->next))
                return 1;

            p = p->next;
        }

        return 0;
    }

`问题 F: 交集问题(线性表) <http://acm.zjgsu.edu.cn/JudgeOnline/problem.php?cid=1565&pid=5>`_
---------------------------------------------------------------------------------------------

:download:`数组实现 <F_array.c>`

.. code-block:: c

    void subset(struct data_container *s, struct data_container *t)
    {
        int i = 0;

        while (i < s->n) {
            if (search(t, s->pData[i]) == -1)
                del(s, i+1);
            else
                i++;
        }
    }

:download:`链表实现 <F_list.c>`

.. code-block:: c

    void subset(struct data_listcontainer *s, struct data_listcontainer *t)
    {
        struct data_node* q = s->head;
        struct data_node* p = q->next;

        while (p) {
            if (search(t, p->data) == -1) {
                q->next = p->next;
                free(p);
                p = q->next;
            } else {
                q = p;
                p = p->next;
            }
        }
    }

代码下载
========

顺序表
------
* :download:`直接使用代码片段 <LinearList_naive.c>`
* :download:`仅支持int的顺序表 <LinearList_int.c>`
* :download:`支持通用类型的顺序表 <LinearList_general.c>`
* :download:`动态申请内存的顺序表 <LinearList_general_dynamic.c>`
* :download:`集合并的顺序表实现 <Union_sequenceList.c>`

单链表
------
* :download:`单链表 <LinkList.c>`
* :download:`集合并的链表实现 <Union_linkList.c>`
* :download:`多项式加法 <polynomial_operation.c>`


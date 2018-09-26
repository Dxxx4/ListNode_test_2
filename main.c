#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <Windows.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };

//����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����� �����֡�
//ʾ�� 1:
//����: 1->2->3->3->4->4->5
//���: 1->2->5
//ʾ�� 2:
//����: 1->1->1->2->3
//���: 2->3
typedef struct ListNode ListNode;
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL){
        return;
    }
    ListNode* prv = head;
    ListNode* node = prv->next;
    ListNode* phead;
    ListNode* del;
    int n = 0;
    while(node != NULL){
        if(prv->val == node->val){
            n = prv->val;
            while(prv != NULL && prv->val == n){
                del = prv;
                if(head == prv){
                    prv = prv->next;
                    if(node != NULL){
                        node = node->next;
                    }
                    head = prv;
                }
                else{
                    phead->next = node;
                    prv = prv->next;
                    if(node != NULL){
                        node = node->next;
                    }
                }
                free(del);
            }
        }
        else{
            phead = prv;
            prv = prv->next;
            node = node->next;
        }
    }
    
    return head;
}


//����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�
//ʾ�� 1:
//����: 1->1->2
//���: 1->2
//ʾ�� 2:
//����: 1->1->2->3->3
//���: 1->2->3
typedef struct ListNode ListNode;
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL){
        return;
    }
    ListNode* prv = head;
    ListNode* node = prv->next;
    ListNode* del;
    ListNode* phead;
    while(node != NULL){
        if(prv->val == node->val){
            del = prv;
            if(prv == head){
                prv = prv->next;
                head = prv;
                if(node != NULL){
                    node = node->next;
                }
            }
            else{
                phead->next = node;
                prv = prv->next;
                node = node->next;
            }
            free(del);
        }
        else{
            phead = prv;
            prv = prv->next;
            node = node->next;
        }
    }
    
    return head;
}


//�ָ�����
//����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
//��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
//ʾ��:
//����: head = 1->4->3->2->5->2, x = 3
//���: 1->2->2->4->3->5
typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x) {
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    ListNode* firmax = head;
    ListNode* phead = firmax;
    while(firmax != NULL && firmax->val < x){
        phead = firmax;
        firmax = firmax->next;
    }
    if(firmax == NULL || firmax->next == NULL){
        return head;
    }
    ListNode* small = firmax->next;
    ListNode* node;
    ListNode* prv = firmax;
    if(small->next == NULL){
        if(small->val >= x){
            return head;
        }
        firmax->next = NULL;
        if(firmax == head){
            small->next = firmax;
            head = small;
            return head;
        }
        phead->next = small;
        small->next = firmax;
        return head;
    }
    while(small != NULL){
        if(small->val < x){
            node = small;
            small = small->next;
            if(firmax == head){
                prv->next = small;
                node->next = firmax;
                phead = node;
                head = node;
            }
            else{
                prv->next = small;
                phead->next = node;
                node->next = firmax;
                phead = phead->next;
            }
        }
        else{
            prv = prv->next;
            small = small->next;
        }
    }
    
    return head;
}





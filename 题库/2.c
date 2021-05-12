#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	int high = 0;
	struct ListNode *root = NULL;
	struct ListNode* p = NULL;

	while(1){
		if(l1 == NULL && l2==NULL){
            if(high>0){
                struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));	
                n->val = 1;
                n->next = NULL;
                if(root == NULL)
                    p=root=n;
                else{
                    p->next = n;	
                    p=n;
                }
            }
			break;
        }
		if(l1 != NULL && l2 != NULL){
			int val = l1->val+l2->val+high;
			int low = val<10?val:val-10;
			high = val>9?1:0;
			struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));	
			n->val = low;
			n->next = NULL;
			if(root == NULL)
				p=root=n;
			else{
				p->next = n;	
				p=n;
			}
			l1=l1->next;
			l2=l2->next;
		}

		else if(l1 != NULL){
			int val = l1->val+high;
			int low = val%10;
			high = val/10;
			struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));	
			n->val = low;
			n->next = NULL;
			if(root == NULL)
				p=root=n;
			else{
				p->next = n;	
				p=n;
			}
			l1=l1->next;
		}
		else if(l2 != NULL){
			int val = l2->val+high;
			int low = val%10;
			high = val/10;
			struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));	
			n->val = low;
			n->next = NULL;
			if(root == NULL)
				p=root=n;
			else{
				p->next = n;	
				p=n;
			}
			l2=l2->next;
		}
	}

	return root;
}

void printList(struct ListNode* r){
	while(1){
		printf("%d, ", r->val);
		if(r->next == NULL)
			break;
		else
			r = r->next;
	}
}

void main(){
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val=2;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val=4;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val=3;
	
	n1->next=n2;
	n2->next=n3;
	n3->next=NULL;

	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val=5;
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val=6;
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n6->val=4;
	
	n4->next=n5;
	n5->next=n6;
	n6->next=NULL;

	struct ListNode* r=addTwoNumbers(n1, n4);
	printList(r);
}

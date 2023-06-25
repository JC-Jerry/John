#include <iostream>
using namespace std;

//定义单链表
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode *next):val(x),next(next){}
};

class solution
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2 )
        {
            ListNode* ret_head=nullptr;
            ListNode* ret_prev=nullptr;
            int i=0;
            int carry=0;
            int s=0;
            while((l1!=nullptr) || (l2!=nullptr))
            {
                ++i;
                cout << "------------in while-----------------------------" << endl;
                ListNode* ret_new=new ListNode(0);

                if(l1==nullptr)
                    s = l2->val+carry;
                else if(l2==nullptr)
                    s = l1->val+carry;
                else
                    s = l2->val+l1->val+carry;
                carry=s/10;
                ret_new->val = s - carry*10;
                
                if(ret_head==nullptr)
                {
                    ret_head = ret_new;
                }
                else
                {
                    ret_prev->next = ret_new;
                }
                ret_prev=ret_new;
                
                if (l1 != nullptr) 
                {
                    l1 = l1->next;
                    // cout << "------------l1 delay----------------------------"<< i << "-------"<< endl;
                }
                if (l2 != nullptr) 
                {
                    l2 = l2->next;
                    // cout << "------------l2 delay----------------------------"<< i << endl;
                }
                if (l1 == nullptr && l2 == nullptr && carry==1) 
                {
                    //添加新节点
                    ListNode* ret_Carry=new ListNode(carry);
                    ret_prev->next=ret_Carry;
                }
            };
            return ret_head;
        }
};


#define le(x) sizeof(x)/sizeof(int) 
// ListNode* CreatLinkList(const int *a[]);

int main()
{
    //input sequence
    int a[]={2,3,4,5,6,7};
    int b[]={2,3,4,5,6,7,8};

    //construct one list for a

    ListNode* head_a = nullptr;
    ListNode* prev_a = nullptr;
    for (size_t i = 0; i < le(a); i++)
    {

        ListNode* newNode_a = new ListNode(a[i]);
        if (i==0)
        {
            head_a=newNode_a;
        }
        else
        {
            prev_a->next=newNode_a;
        }
        prev_a=newNode_a;
    }

    //construct one list for b
    ListNode* head_b = nullptr;
    ListNode* prev_b = nullptr;
    for (size_t i = 0; i < le(b); i++)
    {

        ListNode* newNode_b = new ListNode(b[i]);
        if (i==0)
        {
            head_b=newNode_b;
        }
        else
        {
            prev_b->next=newNode_b;
        }
        prev_b=newNode_b;
    }
    //打印a链表
    ListNode* p_a=head_a;
    while(p_a!=nullptr)
    {
        cout << p_a->val << endl;
        p_a = p_a->next;
    };
    cout << "------------print aaaaa end-----------------------------" << endl;
    //打印b链表
    ListNode* p_b=head_b;
    while(p_b!=nullptr)
    {
        cout << p_b->val << endl;
        p_b = p_b->next;
    };
    cout << "------------------print bbb  end-----------------------" << endl;
    // call add numbers
    solution s;
    ListNode* c =s.addTwoNumbers(head_a,head_b);
    cout << "--------------------call end return c---------------------" << endl;
    //打印c链表
    ListNode* p_c=c;
    while(p_c!=nullptr)
    {
        cout << p_c->val << endl;
        p_c = p_c->next;
    };
    cout << "--------------------print ccc  end---------------------" << endl;

    //释放a 链表内存
    ListNode* current_a = head_a;
    while (current_a != nullptr) {
        ListNode* next = current_a->next;
        delete current_a;
        current_a = next;
    }

    // //释放b 链表内存
    ListNode* current_b = head_b;
    while (current_b != nullptr) {
        ListNode* next = current_b->next;
        delete current_b;
        current_b = next;
    }

    // //释放b 链表内存
    ListNode* current_c = c;
    while (current_c != nullptr) {
        ListNode* next = current_c->next;
        delete current_c;
        current_c = next;
    }

    return 0;
}
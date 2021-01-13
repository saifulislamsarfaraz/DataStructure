#include <bits/stdc++.h>
using namespace std;
/**
    The following structure implements a stack using
    a linked list. The individual elements of the
    linked list are characterized by the structure "Node"
    defined within the stack. Each Node contains a pointer
    to the element next to it in the linked list, and a character
    value. You will need to implement the push(x), pop(), top() &
    size() functions.

    If you implement all four functions correctly, you will get 20
    marks.
*/

struct Stack{
    struct Node{
        char value;
        Node* next;
        Node(){
            next=NULL;
        }
        Node(char ch){
            value=ch;
            next=NULL;
        }
    };


    int no_of_elements;
    Node* head;
    Stack(){
        head=NULL;
        no_of_elements=0;
    }

    int isEmpty(){
    Node* curr = head;
    if(curr==NULL)
         return 1;
        else
        return 0;

      }

    /**
        The following function should
        insert a new element onto the
        stack.
    */

    void push(char ch){
    Node* newNode = new Node(ch);
    newNode -> next = head;
    head = newNode;
    no_of_elements++;
    }

    /**
        The following function should
        delete the element that was last
        inserted onto the stack.
    */

    void pop(){
        if(no_of_elements==0){
            return;
        }
        Node* temp = head;
        head = head -> next;
        free(temp);
        no_of_elements--;
        return;
    }

    /**
        The following function should
        return the character that was last
        inserted onto the stack
    */

    char top(){
        if(head==NULL){
            return '\0';
        }
        return head->value;
    }
    /**
        The following function should return
        the number of elements in the stack.
    */
    int size(){
        return no_of_elements;
    }
};

/**
    The following structure implements a queue using
    a linked list. The individual elements of the
    linked list are characterized by the structure "Node"
    defined within the queue. Each Node contains a pointer
    to the element next to it in the linked list, and a character
    value. You will need to implement the push(x), pop(), front() &
    size() functions.

    If you implement all four functions correctly, you will get 20
    marks.
*/


struct Queue{
    struct Node{
        int value;
        Node* next;
        Node(){
            next=NULL;
        }
        Node(int val){
            value=val;
        }
    };
    int no_of_elements;
    Node *head, *tail;
    Queue(){
        head=NULL;
        tail=NULL;
        no_of_elements=0;
    }
    /**
        The following function should
        insert a new integer onto the
        queue.
    */

    void push(int x){
        no_of_elements++;
        Node* temp = new Node(x);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }else{
        tail->next = temp;
        tail = tail->next;
        }

    }

    /**
        The following function should
        delete the most previously inserted
        integer from the queue. You can assume
        the queue is non-empty.
    */

    void pop(){
    no_of_elements--;
    Node* temp = head;
    head = head->next;
    if(head==NULL){
        tail = NULL;
    }
    free(temp);
    }



    /**
        The following function should return the value
        of the integer that was first inserted into the
        queue. You can assume the queue is non-empty.
    */

    int front(){
    return head->value;;
    }

    /**
        The following function should return the number
        of elements in the queue.
    */

    int size(){
        return no_of_elements;
    }
};

/**
    The following function needs to determine if a
    character sequence s consisting only of '('-s
    and ')'-s is balanced. The conditions for a
    sequence being balanced are as follows:

    1. An empty sequence is balanced.
    2. If a sequence s' is balanced, then (s') is also
       balanced.
    3. If two sequences s1 and s2 are balanced,the
       concatenated sequence s1s2 is also balanced.((()))(())

    You are given s and its corresponding length len.

    If s is balanced, return 1.
    If not, return 0.

    If needed, you can use the stack you implemented above.

    If you implement the function correctly, you will get
    10 marks.
*/

int isBalanced(char s[], int len){

        Stack st;
        for(int i=0; i<len; i++){
            if( s[i]=='(' ){
                st.push(')');//
            }
            else if(s[i]==')'){
                if(st.isEmpty() == 1){
                    return 0;
                }
                else{
                    st.pop();
                }
            }
        }

        if(st.isEmpty())
            return 1;
        else
            return 0;
}



int getPrecedence(char ch){
    if(ch=='*') return 2;
    if(ch=='/') return 2;
    if(ch=='+') return 1;
    if(ch=='-') return 1;
    return 0;
}


/**
    In the following function, you will be given a
    valid infix arithmetic expression, and you will
    have to find its equivalent postfix representation.

    The operators in the expression will either be + (plus),
    -(minus), *(multiplication) and /(integer division, i.e.
    only the integer part of the quotient will be the result
    of the operator (e.g. 5/2=2 not 2.5) should be returned).

    In terms of precedence, remember the PEMDAS/BODMAS rule.
    Multiplication and division will have higher precedence
    than subtraction and addition. The precedence of addition
    and subtraction will be the same. And so will be the
    precedence  of multiplication and division. Additionally
    there may be parantheses (i.e. '(' and ')') and operations
    within  parantheses must gain precedence. The already
    implemented getPrecedence() function above can be used.
    Parantheses should not be included in the postfix expression.


    The operands in the arithmetic expression will each be
    single digit integers.

    The following function will be given a character sequence "infix"
    and its length "len", and an initially empty character sequence
    titled "postfix". Your implementation should fill up the postfix
    array in accordance to the postfix order.

    If you implement the function correctly, you will gain 10 marks.
*/
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
    else
    return 1;
}

void getPostfix(char infix[], int len, char postfix[]){
    Stack st;
    int i = 0;
    int j = 0;//infix: 6+2+(3+2)*6/2
    //postfix: 62+* stack : -
    while(infix[i]!='\0'){
            if(infix[i] >= '0' && infix[i] <= '9'){
                postfix[j++] = infix[i];
            }else if(infix[i] == '('){
                     st.push('(');
            }else if(infix[i] == ')'){
               while(st.size()!=0 && st.top()!='('){
                    char c = st.top();//char thakbe na thakle to dhukbei na
                    st.pop();
                    postfix[j++] = c;
                    }
                    if(st.top()=='('){
                    char c = st.top();
                    st.pop();
                    }
            }else{
            while(st.size()!=0 && getPrecedence(infix[i])<=getPrecedence(st.top()) && st.top()!='('){
                char c = st.top();
                st.pop();
                postfix[j++] = c;
            }
            st.push(infix[i]);
        }
        i++;
    }
    while(st.size()!=0){
        char c = st.top();
        st.pop();
        postfix[j++] = c;
    }
    postfix[j]=0;//NULL
}
//(3+2)*6/2

//3+2*6/2
/**
    The following function function should take a postfix expression
    and return its value. The postfix expression is given as a character
    sequence, all the operands are single digit integers and the operators
    are /, +, -, *. The / stands for integer division, i.e. only the integer
    portion of the quotient will be its results, e.g. 5/2=2.

    The function takes the postfix expression as a string and its length as
    its arguments, and it should return the integer value of the expression.

    In case of postfix evaluation, you might want to implement an integer stack.
    In that case, feel free to fill up the following empty functions in the
    following structure, IntStack. Feel free to copy paste the implementations from
    your previous stack structure.

    [You can also implement stacks and queues as templates in the future. That way you
    can avoid having to write the same code again and again for different data types.
    Feel free to google "Templates in C++"]

    If you implement the function correctly, you will gain 10 marks.
*/


struct IntStack{
    struct Node{
        int value;
        Node* next;
        Node(){
            next=NULL;
        }
        Node(int ch){
            value=ch;
            next=NULL;
        }
    };


    int no_of_elements;
    Node* head;
    IntStack(){
        head=NULL;
        no_of_elements=0;
    }

    /**
        The following function should
        insert a new integer onto the
        stack.
    */

    void push(int ch){
    Node* newNode = new Node(ch);
    newNode -> next = head;
    head = newNode;
    no_of_elements++;
    }

    /**
        The following function should
        delete the integer that was last
        inserted onto the stack.
    */

    void pop(){
        if(no_of_elements==0){
            return;
        }
        Node* temp = head;
        head = head -> next;
        free(temp);
        no_of_elements--;
    }

    /**
        The following function should
        return the integer that was last
        inserted onto the stack
    */

    int top(){
        return head->value;
    }
    /**
        The following function should return
        the number of elements in the stack.
    */
    int size(){
        return no_of_elements;
    }
};
//0=48
//1=49
//2=50
//3=51
//val = 51-48
//postfix: 62/*
//stack :  15  x2 = 3 x1 = 5 res = x1 * x2 = 15
int postfixEvaluation(char postfix[], int len){
    IntStack st;
    int res = 0;
    for(int i = 0; postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){//postfix
            st.push(postfix[i] - '0');
        }else{
        int x2 = st.top();
        st.pop();
        int x1 = st.top();
        st.pop();
        switch(postfix[i]){
        case '+' : res = x1+x2; break;
        case '-' : res = x1-x2; break;
        case '*' : res = x1*x2; break;
        case '/' : res = x1/x2; break;
        }
        st.push(res);
        }
    }
    return st.top();
}


/**
    The following function takes a stack "original"
    as input, and should return another stack which
    contain the same contents of the original stack,
    but in the reverse order.

    If you implement the function correctly, you will gain 10 marks.
*/
//fifo
//original =
//reverse  = 4321
Stack stackReversal(Stack original){
    Stack reversed;
    while(!original.isEmpty()){
        reversed.push(original.top());
        original.pop();
    }
    return reversed;
}


/**
    The following function takes an odd-sized queue as
    the argument. It should return the element in the
    middle of the queue. For example, if the content of
    the queue is 1->3->2->4->5, the function should
    return 2.

    If you implement the function correctly, you will gain 10 marks.
*/
int getMiddleOfQueue(Queue q){
//   int  arr[500] = {0};
//   int i = 0;
//   while(q.size()!=0){
//        arr[i] = q.front();
//        q.pop();
//        i++;
//   }
//   printf("%d\n",arr[i/2]);
//   return arr[i/2];
//   Stack s = new Stack(q.size());
//   int a = q.size()+1/2;
//   while(q.size()!=a){
//   pop()
//   front();
//   while(q.size())
//
//
     int i = 1;
     while(q.size()!=i){
        q.pop();
        i++;
     }
     return q.front();

}

/**
    The following function takes a queue "original"
    as input, and should return another queue which
    contain the same contents of the original queue,
    but in the reverse order.

    If you implement the function correctly, you will gain 10 marks.
*/

Queue queueReversal(Queue original){
    Queue reversed;
    IntStack s;//123456
    //654321//6854321
    while(original.size()>0){
        s.push(original.front());
        original.pop();
    }
    while(s.size()!=0){
        reversed.push(s.top());
        s.pop();
    }
    return reversed;
}

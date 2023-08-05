#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char * arr;
};

int isempty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct stack * ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr, int val){
    if(isfull(ptr)){
        printf("stack is overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;

    }
}
int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("stack is underflow\n");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b){
    if(a=='(' || b==')'){
        return 1;
    }
    if(a=='{' || b=='}'){
        return 1;
    }
    if(a=='[' || b==']'){
        return 1;
    }
    return 0;
}

int parenthesis(char * exp){
    struct stack* sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char* )malloc(sizeof(char));
     char  popped_ch;
     for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isempty(sp)){
                return 0;
            }
            popped_ch=pop(sp);
        
        if(!match(popped_ch, exp[i])){
            return 0;
        }
     }
     }


if(isempty(sp)){
    return 1;
}
else{
    return 0;
}
}

int main(){
    char *exp="[{(45-23)*(12-4)}/5]";
    if(parenthesis(exp)){
        printf("parenthesis is balanced");
    }
    else{
        printf("parenthesis is not balenced");
    }
    return 0;
}
 
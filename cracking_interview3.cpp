//stacks and queues
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <math.h>

using namespace std;
int calculator(char * p);
int performOp(int lVal,int rVal, char c);
char ** convert(char * p);
char * parse(char *p); 
bool isOp(char c); //checked
bool isExponent(char *p); //checked
int precedence(char *p); //checked
bool checkPre(char *p1, char *p2); //checked
int calculator2(char ** ap);
int Exponent1(int base, int e);
int Exponent2(int base, int e);
int Exponent3(int base, int e);
int Exponent4(int base, int e);

// an advice from debugging segmentation fault: set your pointers to NULL when you declare them (or immediately initialize them)
//http://www.cprogramming.com/debugging/segfaults.html

int main(int argc, char const *argv[])
{
	//char a[]="2,3,5,+,*";
	//cout<< calculator(a) << endl;
	//char ** ap=new char*[30];
	//ap=convert(p);
	/*
	while(*ap != 0){
		cout << "*ap = " << *ap << endl;
		if(isOp(**ap)) cout << "**ap is operator" << **ap << endl;
		ap++;
	}
	*/
	//char b[]="2**26"; // no matter the example, always say "wrong input !!" ????????????????
	//char * p = b;
	//char **ap2;
	//ap2=convert(p);
	//int k;
	//k=calculator2(ap2);
	//cout << "the result is: " << k << endl;

    string input;
	char **converted_input;
    do{
            cout << ">>> ";
            getline(cin, input);
            if(input.find("q")==0)
                break;
            if(input=="")continue;
			char *ap=(char *)input.c_str();
			converted_input=convert(ap);
            cout << calculator2(converted_input)<<endl;
    } while(true);
	
	/* 
	char *k=(char *)malloc(sizeof(char)*2);  // why malloc is required here but not elsewhere?
	*k='*';
	*(k+1)='*';
	if(isExponent(k)) cout << "is Exponent" << endl;
	else cout << "not Exponent" << endl;
	*/

	/*
	char *a1=(char *)malloc(sizeof(char)*2);
	*a1='(';
	char *a2=(char *)malloc(sizeof(char)*2);
	*a2=')';
	if(checkPre(a1,a2)) cout << "a1 precedes a2" << endl;
	else cout << "a1 does not precdede a2" << endl;
	*/
	/*char *x, *y;
	y=b;
	while(*y!= '\0' ){  // character arrays, pointers, c++ strings, how to print them, use them etc.????????????????????????
		x=parse(y);
		int k=strlen(x);
		while(*x != '\0'){
			cout << *x << endl;
			x++;
		}
		y=k+y;
		printf("\n");
	}
	*/
}

char ** convert(char * p){ // change "32*(3+5)" into array of "32" "3" "5" "+" "*" to do calculation. refer to http://www.youtube.com/watch?v=LQ-iW8jm6Mk
	stack <string> OpStack;
	int i;
	int n=0; // track number of a[]
	char ** a=new char*[30]; // array of pointers. array members are strings. digits are to be converted to integers with atoi later.
	for(int i=0;i<30;i++){ // should assign memory for what the pointers point to 
		a[i]=new char[11];
	}
	while(*p != '\0'){
		if(isdigit(*p)){
			a[n] = parse(p);
			n+=1;
			while(isdigit(*p)){
				p++;
			}
		}
		
		else if (isOp(*p)) 	// if the char is an operator, check precedence, then push onto OpStack or add to array a[]
		{
			if(OpStack.empty()){
				if(isExponent(p)){
					OpStack.push("**");
					p+=1;
				}
				else {
					OpStack.push(parse(p));
				}
			}
			else{
//				char * p1;
				char * p2;
//				p1=(char *)OpStack.top().c_str(); // ???? could this be the source of problem????????? #### check how to use .c_str()
				char * p1 = new char [3];
				strcpy (p1, OpStack.top().c_str());
				p2=p;
				if(*p == ')'){ // take everything on the stack and add to array, until '(', then discard '('
					while(OpStack.top() != "("){
//						a[n]=(char *)OpStack.top().c_str(); // a[n]=OpStack.top(); n++; //c_str() changes c++ string to c-style string
						strcpy(a[n],OpStack.top().c_str());
						n++;
						OpStack.pop();
					}
					if(OpStack.top() == "("){
						OpStack.pop(); 
					}
				}
				else if(checkPre(p1,p2)){ //*p2 precedes *p1 or if *p1=='('
						OpStack.push(parse(p));
						if(isExponent(p)) p+=1;
				}
				else if(!checkPre(p1,p2)){
//					a[n]=(char *)OpStack.top().c_str();
					strcpy(a[n],OpStack.top().c_str());
					n++;
					OpStack.pop();
					p-=1; // keep pointer at this operator marked by p2, because it needs to compare with the next element in the stack
				}	
			}	
			p++;
		}
		else {
			cout << "error in input" << endl;
			return 0;
		}
	}
	while(!OpStack.empty()){
//		a[n]=(char *)OpStack.top().c_str();
		strcpy(a[n],OpStack.top().c_str());
		n++;
		OpStack.pop();
	}
//	for(int i=0; i<30; i++){ 		// testing
//		if(a[i] != NULL)
//		printf("a[%d] %s\n", i, a[i]);
//	}
	a[n] = 0;
	return a;
}

char * parse(char *p){ // does not parse whole strings with one call; need to move pointer and call parse again to parse different parts,e.g.integers vs operators
	char *a=new char[11]; // limit number of digits in an integer to 10; the extra member is for '\0'
	int num=0; //track the current member of a[]
	if(isdigit(*p)){
		while(isdigit(*p) && num <10){
			a[num]=*p;
			cout << "digits parsed: " << a[num] << "num=" << num << endl;
			p++;
			num++;
		}
		//cout << "new num=" << num << endl; 
		/* used cout to debug, got different results by simply using an extra cout above. the reason is I forgot to 
		allocate memory for a[]. This is the second time i came across this phenomenon */
		a[num] = '\0';
		if(isdigit(*p)){
			cout << "warning: number is too big." << endl;
			return 0;
		}
	}
	else if(isExponent(p)){  
		a[0] = '*';
		a[1] = '*';
		a[2] = '\0';
					cout << "Exponent parsed: " << a[0] << a[1] << endl;

	}
	else if(isOp(*p)){
		a[0] = *p;
		a[1] = '\0';
					cout << "operator parsed: " << a[0] << endl;

	}
	else {
		cout << "error in parsing" << endl;
		return 0;
	}
	 	
	return a;
}

bool isOp(char c){ //+ - * / ( ) **
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
		return true;
	else return false;
}

bool isExponent(char *p){
	if(*p == '*' && *(p+1)=='*' ){ //&& *(p+1) != '\0'  
		//p++; // should pointer move on ??????????
		return true;
	}
	return 0;
}

int precedence(char *p){ 
	if(*p == '+' || *p == '-') return 2;
	else if (isExponent(p)) return 4;
	else if (*p == '/' || *p == '*') return 3;
	else if(*p == '(' || *p == ')') return 5;
	else {
		cout << "error: not an operator" << endl;
		return 0;
	}
}

bool checkPre(char *p1, char *p2){ // if *p2 precedes *p1, return true, (= adding *p2 to stack)
	if(*p1 == '(') {
		return true;
	}
	//else if(*p2 == ')') 
	else if(precedence(p1) >= precedence(p2)) {
		return false;
	}
	else if(precedence(p1) < precedence(p2)){
		return true;
	}
	else {
		cout << "cannot compare precedence" << endl;
		return 0;
	}
}

int calculator2(char ** p){ //takes in the converted array of strings/pointers and do calculation with stack
	stack<int> mystack;
	int rVal, lVal, result;
	result=0;
	//char *a=new char[11];
	//a = *p;
	while(*p != 0){
		if(isdigit(**p)){
			mystack.push(atoi(*p));
		}
		else if(isOp(**p)){
			rVal=mystack.top();//if "rVal=mystack.pop()" error:assigning to 'int' from incompatible type 'void'
			cout << "rVal is " << rVal << endl;
			mystack.pop();
			lVal=mystack.top();
			mystack.pop(); 
			if(isExponent(*p)) result=Exponent4(lVal,rVal);
			else result=performOp(lVal,rVal,**p);
			mystack.push(result);
			cout << "rVal=" << rVal<< " lVal=" <<lVal << " result=" << result << endl;
		}
		
		else {
			cout << "wrong input !!" << *p  << endl; // add **p here, then sometimes can calculate but end up with (extra) segmentation fault
			return result;
		}
		//cout << "**p = " << **p <<endl;
		//cout << "*p = " << *p << endl;
		p+=1;
		//cout << "**p++ = " << **p <<endl; // segmentation fault if add these two lines
		//cout << "*p++ = " << *p << endl;

	}
	if(*p==0) cout << "end of pointer array" << endl;
	//if(!mystack.empty()) cout << "error in input (check number of operands and operators)" << endl;
	return result;
}

//write a calculator using stacks
int calculator(char * p){  // what to do if use string& input (c++) as argument???????????
	//input string uses commas to separate numbers and operators
	stack<int> mystack;
	int i,j, rVal, lVal, result;
	i=0,j=0;
	while(*p != '\0'){  // getc getchar????????
		//store input in a stack. 
		if(isdigit(*p)){//should change to "is integer".the video used sth like ">> num" to check for integers????????
			mystack.push(atoi(p));
		}
		else if(*p=='+' || *p=='-' || *p == '*' || *p=='/'){
			rVal=mystack.top();//if "rVal=mystack.pop()" error:assigning to 'int' from incompatible type 'void'
			mystack.pop();
			lVal=mystack.top();
			mystack.pop();
			result=performOp(lVal,rVal,*p);
			mystack.push(result);
			cout << "rVal=" << rVal<< " lVal=" <<lVal << " result=" << result << endl;
		}
		else if(*p != ','){
			cout << "wrong character" << endl;
			return 0;
			}
		p++;
	}
	if(!mystack.empty()) cout << "error in input (check number of operands and operators)" << endl;
	return result;
}

int performOp(int lVal,int rVal, char c){
	int result;
	if(c=='+') result=lVal+rVal;
	else if(c=='-') result=lVal-rVal;
	else if(c=='*') result=lVal*rVal;
	else if(c=='/') result=lVal/rVal;
	else cout << "error" << endl;
	return result;
}

int Exponent1(int base, int e){
	int result=1;
	if(e<0){
		cout << "cannot calculate this yet" << endl;
		return 0;
	}
	for(int i=0; i<e; i++){
		result=base*result;
	}
	return result;
}

int Exponent2(int base, int e){ // time cost is log2n. but this gives wrong result
	if(e<0){
		cout << "cannot calculate this yet" << endl;
		return 0;
	}
	int b=base;
	while(e>1){
		if (e%2==0)
		{
			base=base*base;
		}
		else {
			base=base*base*b;
		}
		e=e/2;
		cout << "e= " << e <<endl;
		cout << "base= " << base <<endl;

	}
	return base;
}

int Exponent3(int base, int e){ // time cost is log2n
	if(e<0){
		cout << "cannot calculate this yet" << endl;
		return 0;
	}
	int newbase;
	int olde=e;
	if(e==1) return base;
	else if(e==0) return 1;
	else if(e==2) return base*base;
	else{
		while(e>1){
			e=e/2;
			if(olde%2==0){
				newbase=Exponent3(newbase,2);
			}
			else{
				newbase=Exponent3(newbase,2) * base;
			}

			cout << "e= " << e <<endl;
			cout << "newbase= " << newbase <<endl;
	
		}
	}
	return newbase;

}
int Exponent4(int base, int e){ // time cost is log2n
	if(e<1)return 0;
	if(e==1)return base;
	int half=Exponent4(base, e/2);
	if(e%2==1)return base*half*half;
	return half*half;
}

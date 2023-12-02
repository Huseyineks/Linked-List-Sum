#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
	
}Node;

Node* create_Node(int value){
	Node* arr = (Node*)malloc(sizeof(Node));
	arr->value = value;
	arr->next = NULL;
	return arr;           
}
void link_Nodes(Node **arr,int size){
	int index = 0;
	while(index != (size-1)){
		arr[index]->next = arr[index+1];
		index++;
	}
	
	return;
}
int sumOfNodes(Node **arr1,Node **arr2){
	int i = 0;
	int num1 = 0;
	int num2 = 0;
	Node *header =(Node*)malloc(sizeof(Node));
	header = arr1[0];	
	while(header != NULL){
		num1 += header->value*(pow(10,i));
		i++;
		header = header->next;
	}
	i = 0;
	header = arr2[0];
	while(header != NULL){
		num2 += header->value*(pow(10,i));
		i++;
		header = header->next;
	}
	return num1 + num2;
}
Node **create_NodeArray(int sum_value){
	int temp = sum_value;
	int count = 0;
	int i;
	while(sum_value != 0){
		count++;
		sum_value = sum_value/10;
	}
	sum_value = temp;
	Node **number =(Node**)(malloc(sizeof(Node*)*count));
	for(i= 0 ;i < count; i++){
		number[i] = create_Node(sum_value%10);
		sum_value = sum_value/10;
	}
	
	return number;
}
int len_Node(int sum){
	int count = 0;

	while(sum != 0){
		count++;
		sum = sum/10;
	}
	return count;
}
void printf_list(Node **arr){
	Node *header;
	header = arr[0];
	while(header != NULL){
		printf("%d ",header->value);
		
		header = header->next;
	}
	
	return;
}
int main(int argc, char *argv[]) {
	Node **array1 = (Node**)malloc(5*sizeof(Node*));
	array1[0] = create_Node(3);
	array1[1] = create_Node(4);
	array1[2] = create_Node(5);
	array1[3] = create_Node(9);
	array1[4] = create_Node(9);
	Node **array2 = (Node**)malloc(3*sizeof(Node*));
	array2[0] = create_Node(1);
	array2[1] = create_Node(2);
	array2[2] = create_Node(5);
	array2[3] = create_Node(9);
	link_Nodes(array1,5);
	link_Nodes(array2,4);
    int sum = sumOfNodes(array1,array2);
    Node **new_number = create_NodeArray(sum);
	link_Nodes(new_number,len_Node(sum));
    printf_list(new_number);

    
    
	

	
	
	return 0;
}

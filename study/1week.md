단순 연결리스트, 원형 연결리스트

# 1. 연결 리스트란?

순차 자료구조 구현방식은 논리적 순서와 물리적 순서가 같음 → 원소 인덱싱은 쉽지만, 추가와 삭제 연산에서 시간 UP 

따라서 순차 자료구조의 연산 시간과 저장 공간에 대한 문제를 개선한 자료표현 방법 : 연결 자료 구조 or 비순차 자료구조.

연결 자료구조의 구성 단위 : <원소, 주소> → 노드(Node) 

노드 : Data Field (원소 값 저장 부분) + Link Field(주소 저장 부분,포인터 변수)

연결 리스트의 연산 : 리스트의 시작을 가리키는 포인터 변수

# 2. 단순 연결 리스트의 연산과 알고리즘

1. 연결 리스트의 원소 삽입
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/031b487c-7f10-4882-b5b8-370083ee8cfc/Untitled.png)
    
    설명을 하자면, 
    
    (중간) newNode라는 연결리스트를 삽입하기 위해서 
    
    1. newNode → link는 삽입할 위치의 다음 노드를 가르키는 포인터를 저장한다.
    2. newNode를 가르키는 포인터 값을 그 전 노드에 값을 assignment한다.
    
    ```c
    void insertMid(linkedList_h* L, listNode* pre, char* x) {
    	listNode* newNode;
    	newNode = (listNode*)malloc(sizeof(listNode));
    	strcpy(newNode->data, x);
    
    	if (L->head == NULL) { //공백 리스트일 경우 
    		newNode->link = NULL; //새 노드를 첫 번째이자, 마지막 노드로 연결
    		L->head = newNode;
    	}
    	else if(pre == NULL) { //삽입위치 지정 포인터가 pre가 NULL일 경우 
    		newNode->link = L->head;
    		L->head = newNode; 
    	}
    	else
    	{
    		newNode->link = pre->link;// 1번 연산
    		pre->link = newNode;// 2번 연산
    	}
    }
    ```
    
    (처음)
    
    1. newNode의 link필드가 현재 header를 가르킨다.
    2. newNode를 header가 가르키도록 한다.
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3bb274dd-4988-4131-bef1-84480619ea0d/Untitled.png)
    
    ```c
    void insertFirst(linkedList_h* L, char* x) { //첫번째 노드를 삽입하는 연산
    	listNode* newNode; //새로운 노드 포인터 선언
    	newNode = (listNode*)malloc(sizeof(listNode)); //삽입하는 새 노드 메모리 할당
    	strcpy(newNode->data, x); //새 노드의 데이터 필드에 x저장
    	newNode->link = L->head; //1번 
    	L->head = newNode; //2번
    }
    ```
    
    (마지막)
    
    1. temp를 활용하여, temp는 계속해서 연결 리스트의 포인터 값을 따라간다.
    2. temp가 NULL포인터를 만나게 되면, newNode를 마지막 노드(temp)의 다음 노드로 연결
    
    ```c
    void insertLast(linkedList_h* L, char* x) { //마지막 노드로 삽입하는 연산
    	listNode* newNode;
    	listNode* temp;
    
    	newNode = (listNode*)malloc(sizeof(listNode));
    	strcpy(newNode->data, x);
    	newNode->link = NULL;
    	if (L->head == NULL) { //현재 리스트가 공백인 경우
    		L->head = newNode; // 새 노드를 리스트의 시작 노드로 연결
    		return;
    	}
    	
    	//현재 리스트가 공백이 아닌 경우
    
    	temp = L->head;
    	while (temp->link != NULL) temp = temp->link; //현재의 마지막 노드를 찾음
    	temp->link = newNode; //새 노드를 마지막 노드(temp)의 다음 노드로 연결
    }
    ```
    
2. 연결 리스트에 원소 삭제
    
    원소를 삭제하려면, 
    
    동작 1) 삭제할 위치를 찾는다. 
    
    동작 2) 삭제하려는 위치의 노드의 링크를 이전 노드(pre)의 링크에 저장한ㄷ.
    
    k번째 요소를 삭제 했으면, k+1번 부터 n-1 번째 까지 한 칸 씩 이동하면 총 n - k +1만큼 이동 
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9cfd5b41-d9cb-44f0-9784-393efab57bf4/Untitled.png)
    
    ```c
    void deleteNode(linkedList_h* L, listNode* p) {
    	listNode* pre; //삭제할 노드의 선행 노드를 나타낼 포인터
    	if (L->head == NULL) return; //공백 리스트라면 삭제 연산 중단
    	if (L->head->link == NULL) { //리스트에 노드가 한개 만 있을 경우
    		free(L->head); // 첫 번째 노드를 메모리에서 해제하고 
    		L->head = NULL; //리스트 시작 포인터를 NULL
    		return;
    	}
    	else if (p == NULL) return;
    	else {
    		pre = L->head;
    		while (pre->link != p) { //1번
    			pre = pre->link;
    		}
    		pre->link = p->link;//2번
    		free(p);
    	}
    }
    ```
    

# 3. 원형 리스트 연산과 알고리즘

1. 원형 연결 리스트의 원소 삽입
    1. 중간에 삽입하려면...
        
        동작 1) newNode의 link필드를 선행노드(pre)의 link의 값으로 할당한다. 
        
        동작 2) 선행 노드의 link필드(포인터값)에  newNode를 가르킨다. 
        
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0fe3bb12-b1b8-430f-8835-3c1e1976e688/Untitled.png)
    
    ```c
    void insertMidC(ClinkedList_h* CL, ClistNode* pre, char* x) {
    	ClistNode* newNode;
    	newNode = (ClistNode*)malloc(sizeof(ClistNode));
    	strcpy(newNode->data, x);
    	if (CL->head == NULL) { //공백 리스트인 경우
    		CL->head = newNode; 
    		newNode->link = newNode;
    	}
    	else {
    		newNode->link = pre->link; //1번
    		pre->link = newNode; //2번
    	}
    }
    ```
    
    b. 처음에 삽입하려면...
    
    동작 1) haed 노드가 가르키는 노드를 찾는다 → temp에 저장
    
    동작 2) newNode가 가르키는 노드를 temp값으로 할당
    
    동작 3)head 노드가 가르키는 노드를 newNode로 가르킨다.
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f7a34905-be41-48c9-9795-ba1f7883e537/Untitled.png)
    
    ```c
    void insertFirstC(ClinkedList_h* CL, char* x) {
    	ClistNode* newNode, *temp;
    	newNode = (ClistNode*)malloc(sizeof(ClistNode));
    	strcpy(newNode->data, x);
    	if (CL->head == NULL) { //공백 리스트인 경우
    		CL->head = newNode;
    		newNode->link = newNode;
    	}
    	else {
    		temp = CL->head;
    		while (temp->link != CL->head) {//1
    			temp = temp->link;
    		}
    		newNode->link = temp->link; //1 
    		temp->link = newNode; //2 
    		CL->head = newNode; //3
    	}
    }
    ```
    
2. 원형 연결리스트 삭제
    
    동작 1) 삭제할 노드의 선행 노드(pre)는 노드의 다음 노드로 지정한다.
    
    동작 2) 그다음 삭제한 노드의 메모리 공간을 지운다.
    
    동작 3) 만약에 첫 번째 노드를 지울 경우(head 노드) 두 번째 노드가 첫 번째 노드가 되도록 할당한다.
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/aab710ef-3053-4c4e-9c96-039a045a92d6/Untitled.png)
    
    ```c
    void deleteNode(ClinkedList_h* CL, ClistNode* old) {
    	ClistNode* pre;
    	if (CL->head == NULL) return;
    	if (CL->head->link == CL->head) {
    		free(CL->head);
    		CL->head = NULL;
    		return;
    	}
    
    	else if (old == NULL) return;
    	else {
    		pre = CL->head;
    		while (pre->link != old) {
    			pre = pre->link;
    		}
    		pre->link = old -> link; //1
    		if (old == CL->head) {
    			CL->head = old->link; //3
    		}
    		free(old);//2
    	}
    }
    ```

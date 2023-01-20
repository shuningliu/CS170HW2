#include<iostream>
using namespace std;
struct node_t {
        int id;
        string name;
        struct node_t *next;
    };

 /* Iterate through the sorted list (by node_t::id), and find the position after
     * which the new 'node' should be inserted in the list. Ensure that the list
     * is kept sorted. Return the element just before the newly inserted one.
     * If the new 'node' should be inserted at the beginning, return NULL.
     */
    node_t *
    find_insert_pos(node_t *head, node_t *node)
    {
        if (head == NULL) return NULL;

        node_t *ret = NULL;

        if(head->id>=node->id)return NULL;  //In this case, it has smallest id and stay at behind.
while(head->next!=NULL){
	if(head->next->id>=node->id){
		return head;
	}
	head = head->next;
}
return head;  //In this case, node has largest ID and stay at last position.
    }

    
    node_t * insert(node_t *head, node_t *node)
    {
        if (head == NULL) return node;

        // find the proper position to insert this node pair.
        node_t *pos = find_insert_pos(head, node);

        if(pos==NULL){
	node->next = head;
	return node; //Insert at beginning
}
node->next = pos->next;
pos->next = node; //Insert at beginning or end;

        return head;
    }

    int
    main(void)
    {
        node_t *student_list = NULL;

        // init first student Alice
        node_t *student_1 = new node_t();
        student_1->id = 1002;
        student_1->name="Alice";
        student_1->next = NULL;

        // init second student Bob
        node_t *student_2 = new node_t();
        student_2->id = 1000;
        student_2->name="Bob";
        student_2->next = NULL;

        node_t *student_3 = new node_t();
        student_3->id = 999;
        student_3->name="zz";
        student_3->next = NULL;

        node_t *student_4 = new node_t();
        student_4->id = 9999;
        student_4->name="zz9";
        student_4->next = NULL;

        node_t *student_5 = new node_t();
        student_5->id = 1001;
        student_5->name="zz19";
        student_5->next = NULL;
        student_list = insert(student_list, student_1);
        student_list = insert(student_list, student_2);
         student_list = insert(student_list, student_3);
         student_list = insert(student_list, student_4); student_list = insert(student_list, student_5);

        // now we should have a student list:
        //    <1000, Bob> -> <10002, Alice> -> NULL
        while(student_list!=nullptr){
            cout<<student_list->id<<" "<<student_list->name<<" ";
            student_list = student_list->next;
        }

        

        return 0;
    }
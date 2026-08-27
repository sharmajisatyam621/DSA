/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 ==null){
            return list2;
        }
        if(list2 == null){
            return list1;
        }
        ListNode Temp = new ListNode(0);
        ListNode curr_node = Temp;
        while(list1!=null&&list2!=null){
            if(list1.val<list2.val){
                curr_node.next=list1;
                list1=list1.next;
            }
            else{
                curr_node.next=list2;
                list2=list2.next;
            }
            curr_node= curr_node.next;
        }
        if(list1!=null){
            curr_node.next=list1;
        }
        if(list2!=null){
            curr_node.next=list2;
        }
        // // or we cam simply use ternary operator 
        // curr_node.next = (list1 != null) ? list1 : list2;
        return Temp.next;
    }
}
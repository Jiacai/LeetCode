public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) return null;
        RandomListNode node = head;
        // copy node and change the structure
        while (node != null) {
            RandomListNode copyNode = new RandomListNode(node.label);
            copyNode.next = node.next;
            node.next = copyNode;
            node = copyNode.next;
        }        
        node = head;
        while (node != null) {
            node.next.random = node.random == null ? null : node.random.next;
            node = node.next.next;
        }
        // re-build the structure
        node = head;
        RandomListNode copyHead = head.next;
        while (node != null) {
            RandomListNode copyNode = node.next;
            node.next = copyNode.next;
            copyNode.next = node.next == null ? null : node.next.next;
            node = node.next;
        }
        return copyHead;
    }
}
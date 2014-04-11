public class Solution {
    HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        map.clear();
        return cloneNode(node);
    }
     
    private UndirectedGraphNode cloneNode(UndirectedGraphNode node)
    {
        if (node == null) return null;
        if (map.containsKey(node)) return map.get(node);
        else
        {
            UndirectedGraphNode copy = new UndirectedGraphNode(node.label);
            map.put(node, copy);
            for (UndirectedGraphNode n : node.neighbors)
            {
                copy.neighbors.add(cloneNode(n));
            }
            return copy;
        }
    }
}
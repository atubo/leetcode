import java.util.*;

public class SimplifyPath {
    public String simplifyPath(String path) {
        String[] dirs = path.split("/");
        LinkedList<String> dirStack = new LinkedList<>();
        for (int i = 0; i < dirs.length; i++) {
            String s = dirs[i];
            if (s.isEmpty() || s.equals(".")) continue;
            if (s.equals("..")) {
                if (!dirStack.isEmpty()) dirStack.pollLast();
            } else {
                dirStack.add(s);
            }
        }
        if (dirStack.isEmpty()) return "/";
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < dirStack.size(); i++) {
            sb.append("/" + dirStack.get(i));
        }
        return sb.toString();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        SimplifyPath solution = new SimplifyPath();
        String t = solution.simplifyPath(s);
        System.out.println(t);
    }
}
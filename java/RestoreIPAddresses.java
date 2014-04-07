import java.util.*;

public class RestoreIPAddresses {
    public ArrayList<String> restoreIpAddresses(String s) {
        ArrayList<String> result = new ArrayList<>();
        int len = s.length();
        for (int i = 1; i <= len-3; i++) {
            if (!validDomain(s, 0, i)) break;
            
            for (int j = i+1; j <= len-2; j++) {
                if (!validDomain(s, i, j)) break;
                
                for (int k = j+1; k <= len-1; k++) {
                    if (!validDomain(s, j, k)) break;
                    
                    if (!validDomain(s, k, len)) continue;
                    
                    String ipAddress = s.substring(0, i) + "." + s.substring(i, j) + "." +
                                       s.substring(j, k) + "." + s.substring(k, len);
                    result.add(ipAddress);
                }
            }
        }
        return result;
    }
    
    public boolean validDomain(String s, int i, int j) {
        if (j-i > 3) return false;
        if (j-i > 1 && s.charAt(i) == '0') return false;
        int d = Integer.parseInt(s.substring(i, j));
        return d <= 255;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        RestoreIPAddresses solution = new RestoreIPAddresses();
        ArrayList<String> result = solution.restoreIpAddresses(s);
        for (String rs: result) {
            System.out.println(rs);
        }
    }
}
                    
                    
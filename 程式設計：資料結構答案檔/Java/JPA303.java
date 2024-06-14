import java.util.*;

public class JPA303 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        Map<String, Integer> combinationCounts = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            String[] fruits = scanner.nextLine().split(" ");
            Arrays.sort(fruits);
            Set<String> uniqueCombinations = new HashSet<>();
            
            for (int j = 0; j < fruits.length; j++) {
                for (int k = j + 1; k < fruits.length; k++) {
                    String combination = fruits[j] + " " + fruits[k];
                    if (!uniqueCombinations.contains(combination)) {
                        combinationCounts.put(combination, combinationCounts.getOrDefault(combination, 0) + 1);
                        uniqueCombinations.add(combination);
                    }
                }
            }
        }
        
        List<Map.Entry<String, Integer>> combinationsList = new ArrayList<>(combinationCounts.entrySet());
        combinationsList.sort(new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                int countCompare = o2.getValue().compareTo(o1.getValue());
                if (countCompare == 0) {
                    return o2.getKey().compareTo(o1.getKey());
                }
                return countCompare;
            }
        });
        
        for (int i = 0; i < Math.min(3, combinationsList.size()); i++) {
            Map.Entry<String, Integer> entry = combinationsList.get(i);
            System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
}

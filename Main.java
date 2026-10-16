
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Dynamic array to store multiple wafer objects
        ArrayList<Wafer> wafers = new ArrayList<>();

        System.out.println("========================================");
        System.out.println("      SEMICONDUCTOR WAFER AI");
        System.out.println("           JAVA OOP MODULE");
        System.out.println("========================================");

        // 1. Create Wafer object
        Wafer wafer = new Wafer(
            "W001",
            "Center_0001.png"
        );

        // Store the wafer in the dynamic array
        wafers.add(wafer);

        // 2. Create Defect object
        Defect defect = new Defect(
            "Donut",
            90.92
        );

        // 3. Create InspectionResult object
        InspectionResult result = new InspectionResult(
            defect,
            "DEFECTIVE"
        );

        // 4. Basic analyzer
        System.out.println("\n----- BASIC ANALYSIS -----");

        WaferAnalyzer basicAnalyzer =
            new WaferAnalyzer("Basic Wafer Analyzer");

        basicAnalyzer.analyze(wafer);

        // 5. Method overriding and inheritance
        System.out.println("\n----- WAFER ANALYSIS -----");

        Analyzer analyzer = basicAnalyzer;
        analyzer.showSystemMessage();
        analyzer.analyze(wafer, result);

        // 6. super keyword demonstration
        System.out.println("\n----- SUPER KEYWORD DEMO -----");

        AIWaferAnalyzer aiAnalyzer =
            new AIWaferAnalyzer("AI Wafer Analyzer");

        aiAnalyzer.analyze(wafer, result);

        // 7. AI analysis
        aiAnalyzer.showAIAnalysis(result);

        // 8. Interface demonstration
        System.out.println("\n----- INTERFACE DEMO -----");

        aiAnalyzer.generateReport();
        aiAnalyzer.exportData();

        // 9. Hierarchical inheritance
        System.out.println("\n----- IMAGE ANALYSIS -----");

        ImageAnalyzer imageAnalyzer = new ImageAnalyzer();
        imageAnalyzer.analyze(wafer, result);

        // 10. Dynamic array operations
        int choice;

        do {
            System.out.println("\n----- DYNAMIC WAFER ARRAY -----");
            System.out.println("1. Add New Wafer");
            System.out.println("2. Display All Wafers");
            System.out.println("3. Search Wafer by ID");
            System.out.println("4. Count Total Wafers");
            System.out.println("0. Continue to Flask / Exit");
            System.out.print("Enter choice: ");

            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Enter Wafer ID: ");
                    String id = sc.nextLine();

                    System.out.print("Enter image name: ");
                    String imageName = sc.nextLine();

                    wafers.add(new Wafer(id, imageName));

                    System.out.println("Wafer added successfully!");
                    break;

                case 2:
                    if (wafers.isEmpty()) {
                        System.out.println("No wafers available.");
                    } else {
                        for (Wafer w : wafers) {
                            w.displayWaferInfo();
                            System.out.println("--------------------");
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter Wafer ID to search: ");
                    String searchId = sc.nextLine();

                    boolean found = false;

                    for (Wafer w : wafers) {
                        if (w.getWaferId().equalsIgnoreCase(searchId)) {
                            System.out.println("Wafer found:");
                            w.displayWaferInfo();
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        System.out.println("Wafer not found.");
                    }
                    break;

                case 4:
                    System.out.println("Total wafers: " + wafers.size());
                    break;

                case 0:
                    System.out.println("Leaving dynamic array menu.");
                    break;

                default:
                    System.out.println("Invalid choice. Try again.");
            }

        } while (choice != 0);

        // 11. Flask backend connection
        System.out.println("\n----- FLASK CONNECTION -----");

        FlaskClient.checkConnection();

        System.out.println("\n===== PROGRAM COMPLETED =====");

        sc.close();
    }
}


public class Wafer {

    private final String waferId;
    private final String imageName;

    // Constructor
    public Wafer(String waferId, String imageName) {
        this.waferId = waferId;
        this.imageName = imageName;
    }

    // Getters
    public String getWaferId() {
        return waferId;
    }

    public String getImageName() {
        return imageName;
    }

    // Display wafer information
    public void displayWaferInfo() {
        System.out.println("Wafer ID   : " + waferId);
        System.out.println("Image Name : " + imageName);
    }

    // Main method to demonstrate an array of wafers
    public static void main(String[] args) {

        // Create an array of 3 wafers
        Wafer[] wafers = new Wafer[3];

        // Create and store wafer objects
        wafers[0] = new Wafer("W001", "Center_0001.png");
        wafers[1] = new Wafer("W002", "Donut_0002.png");
        wafers[2] = new Wafer("W003", "Scratch_0003.png");

        // Display all wafers
        System.out.println("===== SEMICONDUCTOR WAFER AI =====");

        for (int i = 0; i < wafers.length; i++) {
            wafers[i].displayWaferInfo();
            System.out.println("------------------------------");
        }
    }
}

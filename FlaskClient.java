
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;

public class FlaskClient {

    private static final String API_URL =
            "http://127.0.0.1:5000/";

    public static void checkConnection() {

        try {
            HttpClient client = HttpClient.newHttpClient();

            HttpRequest request = HttpRequest.newBuilder()
                    .uri(URI.create(API_URL))
                    .GET()
                    .build();

            HttpResponse<String> response =
                    client.send(
                            request,
                            HttpResponse.BodyHandlers.ofString()
                    );

            System.out.println("\n----- FLASK CONNECTION -----");
            System.out.println("Status Code : " + response.statusCode());
            System.out.println("Backend Response:");
            System.out.println(response.body());

        } catch (Exception e) {
            System.out.println("\nFlask connection failed.");
            System.out.println("Make sure Flask is running.");
            System.out.println(e.getMessage());
        }
    }
}

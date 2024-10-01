public class Main
{
	static final String DEFAULT_HOST = "127.0.0.1";
	static final int DEFAULT_PORT = 3331;

	public static void main(String argv[])
	{
		String host = DEFAULT_HOST;
		int port = DEFAULT_PORT;
		
		Client client = null;
		Window window = null;
		try {
			client = new Client(host, port);
			window = new Window(client);
			System.out.println("Starting Server on port " + port);  
		}
		catch(Exception e) {
			e.printStackTrace();
			System.out.println("Could not start Server on port  " + port); 
		}
	}
}
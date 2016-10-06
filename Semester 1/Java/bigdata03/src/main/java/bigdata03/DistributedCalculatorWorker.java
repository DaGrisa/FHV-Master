package bigdata03;

import java.util.concurrent.Callable;

import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.core.GenericType;

public class DistributedCalculatorWorker implements Callable<Result> {
	private String host;
	private int numOfThrows;
	private Client client;

	public DistributedCalculatorWorker(String host, int numOfThrows) {
		this.host = host;
		this.numOfThrows = numOfThrows;
		client = ClientBuilder.newClient();
	}

	public Result call() throws Exception {
		return client.target("http://" + host + "/bigdata02/pi").queryParam("numOfThrows", numOfThrows)
				.request().get(new GenericType<Result>(){});
	}

}

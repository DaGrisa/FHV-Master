package bigdata03;

import java.io.UnsupportedEncodingException;
import java.util.concurrent.ExecutionException;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;

@Path("pi")
public class DistributedController {
	@GET
	@Produces(MediaType.APPLICATION_XML)
	public Result calc(@QueryParam("numOfThrows") int numOfThrows, @QueryParam("worker") String worker) throws UnsupportedEncodingException, InterruptedException, ExecutionException{
		Result result = new Result();
		long startTime = System.nanoTime();
		if(numOfThrows > 0 && !worker.isEmpty()){
			result.setValue(DistributedCalculator.distribute(numOfThrows, worker));
		}
		result.setRuntimeNs(System.nanoTime() - startTime);
		return result;
	}
}

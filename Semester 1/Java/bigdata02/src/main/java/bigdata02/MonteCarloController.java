package bigdata02;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.QueryParam;

@Path("pi")
public class MonteCarloController {
	@GET
	public Result calc(@QueryParam("numOfThrows") int numOfThrows){
		Result result = new Result();
		long startTime = System.nanoTime();
		if(numOfThrows > 0){
			result.setValue(MonteCarloCalculator.calc(numOfThrows));
		}
		result.setRuntimeNs(System.nanoTime() - startTime);
		return result;
	}
}

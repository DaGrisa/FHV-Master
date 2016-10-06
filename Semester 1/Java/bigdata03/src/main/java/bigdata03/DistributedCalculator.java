package bigdata03;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class DistributedCalculator {

	public static double distribute(int numOfThrows, String worker)
			throws InterruptedException, ExecutionException, UnsupportedEncodingException {
		Integer numOfWorker = worker.split(",").length;
		Integer numOfThreads = numOfWorker;
		Integer numOfThrowsWorker = numOfThrows / numOfWorker;
		Integer remainderThrows = numOfThrows % numOfWorker;
		Double resultSum = 0d;

		worker = URLDecoder.decode(worker, "UTF-8");

		ExecutorService executor = Executors.newFixedThreadPool(numOfThreads);
		List<Future<Result>> resultList = new ArrayList<Future<Result>>();

		for (String host : worker.split(",")) {
			Callable<Result> workerCall = new DistributedCalculatorWorker(host, numOfThrowsWorker + remainderThrows);
			remainderThrows = 0;
			resultList.add(executor.submit(workerCall));
		}

		for (Future<Result> result : resultList) {
			resultSum += result.get().getValue();
		}

		return resultSum / numOfWorker;
	}

}

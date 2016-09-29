package bigdata02;

import java.util.Random;

public class MonteCarloCalculator {
	public static double calc(int numOfThrows) {
		Random randomGen = new Random(System.nanoTime());
		int hits = 0;
		
		for (int i = 0; i <= numOfThrows; i++) {
			double xPos = (randomGen.nextDouble()) * 2 - 1.0;
			double yPos = (randomGen.nextDouble()) * 2 - 1.0;
			if (isInside(xPos, yPos)) {
				hits++;
			}
		}
		
		return 4 * ((double)hits / numOfThrows); // cast => else int division
	}
	
	private static boolean isInside(double xPos, double yPos) {
		double distance = Math.sqrt((xPos * xPos) + (yPos * yPos));
		return (distance <= 1);
	}
}
package bigdata03;

import javax.xml.bind.annotation.*;

@XmlRootElement
public class Result {
	private double value;
	private long runtimeNs;

	public void setValue(double calc) {
		this.value = calc;
	}

	public void setRuntimeNs(long nanos) {
		this.runtimeNs = nanos;
	}

	public double getValue() {
		return this.value;
	}

	public long getRuntimeNs() {
		return this.runtimeNs;
	}
}

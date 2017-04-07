package at.grisa.justlang.symbol;

import java.util.ArrayList;
import java.util.HashMap;

public class NameList {
	private HashMap<String, Integer> nameIndices;
	private ArrayList<String> names;

	public NameList() {
		nameIndices = new HashMap<String, Integer>();
		names = new ArrayList<String>();
	}

	public Integer addName(String name) {
		Integer index = nameIndices.get(name);
		if (index == null) {
			names.add(name);
			index = names.indexOf(name);
			nameIndices.put(name, index);
		}
		return index;
	}
}
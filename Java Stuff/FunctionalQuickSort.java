package de.maibornwolff.fpjava.session3.homework;

import java.util.ArrayList;
import java.util.List;

public class FunctionalQuickSort {

  public static List<Integer> quickSortInteger(final List<Integer> listToSort) {
    // uses the first element as the pivot element
    return quickSortGen(listToSort);
  }

  public static <T extends Comparable<? super T>> List<T> quickSortGen(final List<T> listToSort) {
    // uses the first element as the pivot element
    if (listToSort.size() <= 1) {
      return listToSort;
    }

    T pivotElement = listToSort.get(0);
    // ignore first element when building left subList otherwise infinite loop
    List<T> smallerThanPivot = listToSort.subList(1, listToSort.size()).stream()
        .filter(element -> element.compareTo(pivotElement) <= 0).toList();
    List<T> greaterThanPivot = listToSort.stream().filter(element -> element.compareTo(pivotElement) > 0).toList();

    return concatLists(quickSortGen(smallerThanPivot), List.of(pivotElement), quickSortGen(greaterThanPivot));
  }

  @SafeVarargs
  private static <T extends Comparable<? super T>> List<T> concatLists(final List<T>... lists) {
    assert lists.length > 0;
    List<T> newList = new ArrayList<>(lists[0]);
    for (int i = 1; i < lists.length; i++) {
      newList.addAll(lists[i]);
    }
    return newList;
  }

}

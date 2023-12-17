#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Food {
public:
  string name;
  int rating;

  Food(string name, int rating) : name(name), rating(rating) {}

  bool operator<(const Food &other) const {
    if (rating == other.rating) {
      return name < other.name;
    }
    return rating > other.rating;
  }
};

class FoodRatings {
  unordered_map<string, int> m_foodToRating;
  unordered_map<string, string> m_foodToCuisine;
  unordered_map<string, set<Food>> m_cuisineToFood;

public:
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {

    for (int i = 0; i < foods.size(); ++i) {
      m_foodToRating[foods[i]] = ratings[i];
      m_foodToCuisine[foods[i]] = cuisines[i];
      m_cuisineToFood[cuisines[i]].insert(Food(foods[i], ratings[i]));
    }
  }

  void changeRating(string food, int newRating) {
    auto oldFood = m_cuisineToFood[m_foodToCuisine[food]].find(
        Food(food, m_foodToRating[food]));
    m_cuisineToFood[m_foodToCuisine[food]].erase(oldFood);

    m_foodToRating[food] = newRating;
    m_cuisineToFood[m_foodToCuisine[food]].insert(Food(food, newRating));
  }

  string highestRated(string cuisine) {
    return m_cuisineToFood[cuisine].begin()->name;
  }
};

#include<iostream>
#include<map>
#include<set>
#include<unordered_set>
using namespace std;

class Twitter {

private:
    unordered_map<int, vector<int>> userTweetsMap;
    unordered_map<int, unordered_set<int>> userFollowingMap;
    unordered_map<int, int> tweetTimestampMap;
    int timestamp;

public:
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweetsMap[userId].push_back(tweetId);
        tweetTimestampMap[tweetId] = ++timestamp;
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> followingSet;
        if (userFollowingMap.find(userId) != userFollowingMap.end()) {
            followingSet = userFollowingMap[userId];
        }

        unordered_set<int> allRelevantUsers = followingSet;
        allRelevantUsers.insert(userId);

        priority_queue<pair<int, int>> tweetQueue;
        for (int currentUserId : allRelevantUsers) {
            if (userTweetsMap.find(currentUserId) != userTweetsMap.end()) {
                vector<int>& currentUserTweets = userTweetsMap[currentUserId];
              
                if (!currentUserTweets.empty()) {
                    int tweetsToAdd = min(10, static_cast<int>(currentUserTweets.size()));
                    for (int i = currentUserTweets.size() - 1; 
                         i >= static_cast<int>(currentUserTweets.size()) - tweetsToAdd; 
                         i--) {
                        int tweetId = currentUserTweets[i];
                        tweetQueue.push({tweetTimestampMap[tweetId], tweetId});
                    }
                }
            }
        }

        vector<int> newsFeed;
        while (!tweetQueue.empty() && newsFeed.size() < 10) {
            newsFeed.push_back(tweetQueue.top().second);
            tweetQueue.pop();
        }
      
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowingMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (userFollowingMap.find(followerId) != userFollowingMap.end()) {
            userFollowingMap[followerId].erase(followeeId);
        }
    }
};

//--------------------------------------------------

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
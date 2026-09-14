class Twitter {
public:
    int time = 0;

    // follower -> set of people they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;

        // Add user's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Add tweets of people user follows
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        // Get 10 most recent tweets
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
/**
 * 355. 设计推特
 * 设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近 10 条推文。
 * 实现 Twitter 类：
 * Twitter() 初始化简易版推特对象
 * void postTweet(int userId, int tweetId) 根据给定的 tweetId 和 userId 创建一条新推文。
 * 每次调用此函数都会使用一个不同的 tweetId 。
 * List<Integer> getNewsFeed(int userId) 检索当前用户新闻推送中最近  10 条推文的 ID 。
 * 新闻推送中的每一项都必须是由用户关注的人或者是用户自己发布的推文。推文必须 按照时间顺序由最近到最远排序 。
 * void follow(int followerId, int followeeId) ID 为 followerId 的用户开始关注 ID 为 followeeId 的用户。
 * void unfollow(int followerId, int followeeId) ID 为 followerId 的用户不再关注 ID 为 followeeId 的用户。
 * 
 * https://leetcode.cn/problems/design-twitter/
 */

class Twitter {
    struct Tweet {
        int tweetId;    // 推文id
        int ctime;      // 创建时间

        Tweet(int id, int time) : tweetId(id), ctime(time) {}

        // 优先队列用到的自定义优先级
        bool operator< (const Tweet& info) const {
            return ctime < info.ctime;
        }
    };

    struct TweetInfo : public Tweet {
        // other fields, e.g., content
        // string content;

        TweetInfo(int id, int time) : Tweet(id, time) {}

        TweetInfo(const TweetInfo& info) : Tweet(info.tweetId, info.ctime) {
        }
    };

    struct UserInfo {
        // 该user关注的人, user id
        unordered_set<int> followee;

        // 该user发送的tweet, 主要记录tweetId、ctime
        list<Tweet> tweets;
    };


    // twitter系统用户信息，关注的人、发的推文
    // user id --> UserInfo
    unordered_map<int, UserInfo> users;

    // twitter系统用户发的推文
    // tweet id --> TweetInfo
    unordered_map<int, TweetInfo*> tweets;

    // 全局time，每发一个新的推文，now自增，以表明每条推文的创建时间
    int now;

public:
    Twitter() {
        users.clear();
        tweets.clear();
        now = 0;
    }

    void postTweet(int userId, int tweetId) {
        int cur = ++now;
        TweetInfo info(tweetId, cur);
        tweets[tweetId] = &info;     // 持久化推文
        users[userId].tweets.push_front(Tweet(tweetId, cur));
    }
    
    // 合并用户userId关注的用户所发推文的链表
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet> q;

        // 对该用户userId关注的每个用户
        for (auto uid : users[userId].followee) {
            list<Tweet>::iterator it = users[uid].tweets.begin();
            for (; it != users[uid].tweets.end(); ++it)
                q.push(*it);
        }

        // 处理该用户自己发的推文
        list<Tweet>::iterator it = users[userId].tweets.begin();
        for (; it != users[userId].tweets.end(); ++it)
            q.push(*it);

        // 输出前10条推文
        vector<int> res;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            res.push_back(p.tweetId);
            if (res.size() >= 10) break;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].followee.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId].followee.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
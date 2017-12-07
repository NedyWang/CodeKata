//
// Created by root on 11/29/17.
//



//
//class UnitTest
//{
//public:
//    UnitTest() {
//        try {
//            solution = new Solution();
//            this->unit_test_lengthOfLongestSubstring();
//            this->unit_test_findMedianSortedArrays();
//        }
//        catch (exception &except) {
//            if (solution)
//                delete solution;
//            filebuf fp;
//            fp.open("./except.out", ios::out);
//            ostream output(&fp);
//            output << except.what() << endl;
//            fp.close();
//        }
//    }
//    ~UnitTest(){
//        if (solution){
//            delete solution;
//        }
//    }
//
//private:
//
//    void unit_test_findMedianSortedArrays() {
//        int nums_1[] = {2,3,4,5,6,7,9,10};
//        int nums_2[] = {1,8};
//        vector<int> nums1(nums_1, nums_1 + sizeof(nums_1)/sizeof(int)), nums2(nums_2, nums_2 + sizeof(nums_2)/sizeof(int));
//        assert(solution->findMedianSortedArrays(nums1, nums2) == 5.5);
//    }
//
//    void unit_test_lengthOfLongestSubstring() {
//        assert(solution->lengthOfLongestSubstring("abcabcbb") == 3);
//        assert(solution->lengthOfLongestSubstring("bbbbb") == 1);
//        assert(solution->lengthOfLongestSubstring("pwwkew") == 3);
//    }
//
//    void unit_test_longestPalindrome() {
//        assert(solution->longestPalindrome("babad") == "bab");
//        assert(solution->longestPalindrome("cbbd") == "bb");
//        assert(solution->longestPalindrome("aaaaaaa") == "aaaaaaa");
//    }
//
//    void unit_test_zigzarg_convert() {
//        assert(solution->zigzarg_convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
//    }
//
//private:
//    Solution *solution;
//};
//
void unitTestNextPermutation();

int main(int argc, char const *argv[])
{
//    UnitTest ut;
    unitTestNextPermutation();
    return 0;
}

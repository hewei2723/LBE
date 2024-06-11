package RegLogin;

public class UserDaoForArray {
    private User[] data;
    private int count;

    public UserDaoForArray() {
        data = new User[10];
    }

    public boolean add(User user) {

        if (count == data.length) {
            return false;
        }
        for (int i = 0; i < count; i++) {

            if (data[i].getUserName().equals(user.getUserName())) {
                return false;
            }
        }
        data[count] = user;
        count++;
        return true;
    }
    public User getUser(String userName,String password) {
        for (int i = 0; i < count; i++) {
            if (data[i].getUserName().equals(userName) && data[i].getPassword().equals(userName)) {
                return new User(userName, password);
            }
        }
        return null;
    }
}

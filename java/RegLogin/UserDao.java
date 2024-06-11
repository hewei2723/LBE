package RegLogin;

public interface UserDao {
    public boolean addUser(User user);
    public boolean getUser(String username, String password);
}

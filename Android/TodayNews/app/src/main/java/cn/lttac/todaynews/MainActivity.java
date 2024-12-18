package cn.lttac.todaynews;
import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;
import com.google.android.material.bottomnavigation.BottomNavigationView;

import java.util.Objects;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Objects.requireNonNull(getSupportActionBar()).hide();
        setContentView(R.layout.activity_main);

        // 获取底部导航栏
        BottomNavigationView bottomNavigationView = findViewById(R.id.bottom_navigation);
        // 设置底部导航栏的点击事件
        bottomNavigationView.setOnItemSelectedListener(item -> {
            Fragment selectedFragment;

            // 判断点击的导航项
            if (item.getItemId() == R.id.nav_publish) {
                // 如果点击的是发布按钮，则显示发布页面
                selectedFragment = new AddNews();
            } else if (item.getItemId() == R.id.nav_my) {
                // 如果点击的是我的按钮，则显示未登录页面
                selectedFragment = new UnLogin();
            } else { // 默认选中主页
                // 如果点击的是其他按钮，则显示主页
                selectedFragment = new Home();
            }
            // 切换页面
            switchFragment(selectedFragment);
            return true;
        });
        // 默认加载主页
        switchFragment(new Home());
    }

    // 切换Fragment
    private void switchFragment(Fragment fragment) {
        // 获取FragmentManager
        FragmentManager fragmentManager = getSupportFragmentManager();
        // 开启事务
        FragmentTransaction transaction = fragmentManager.beginTransaction();
        // 替换Fragment
        transaction.replace(R.id.fragment_container, fragment);
        // 提交事务
        transaction.commit();
    }

}

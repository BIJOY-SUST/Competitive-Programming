vector<pll >v;
    for(int cs=1;cs<=t;cs++){
        ll d,n;
        v.clear();
        scanf("%lld%lld",&d,&n);
        for(ll i=0;i<n;i++){
            ll k,s;
            scanf("%lld%lld",&k,&s);
            v.push_back({k,s});
        }
        sort(v.begin(),v.end());
        if(n==1){
            double t=(double)(d-v[0].first)/v[0].second*1.0;
            double ans=(double)d/t*1.0;
            printf("Case #%d: %.6f\n",cs,ans);
        }
        if(n==2){
            if(v[0].second>v[1].second){
                double t=(double)v[0].second-(double)v[1].second;
                double dd=(double)v[1].first-(double)v[0].first;
                double s=(double)(dd*v[1].second)/t*1.0;
//                    cout<<t<< " "<<d<<" "<<" "<<s<<endl;
                t=(double)dd/t*1.0;
                if(s<d) dis.push_back({s,t});
            }
            else{

            }
            printf("Case #%d: %.6f\n",cs,ans);
        }

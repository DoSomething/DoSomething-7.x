Vagrant.configure("2") do |config|
  ## Chose your base box
  config.vm.box = "precise64"
  config.vm.box_url = "http://files.vagrantup.com/precise64.box"
  
  config.vm.provider "virtualbox" do |v|
    v.customize ["modifyvm", :id, "--memory", 1024]
  end

  ## For masterless, mount your salt file root
  config.vm.synced_folder "salt/roots/", "/srv/"
  
  # Without Varnish
  config.vm.network :forwarded_port, guest: 8888, host: 8888
  
  # With Varnish
  config.vm.network :forwarded_port, guest: 6081, host: 9999
  
  # Jenkins
  config.vm.network :forwarded_port, guest: 8080, host: 11111
  
  ## Use all the defaults:
  config.vm.provision :salt do |salt|
    
    salt.verbose = true
    salt.minion_config = "salt/minion.conf"
    salt.run_highstate = true

  end
end
